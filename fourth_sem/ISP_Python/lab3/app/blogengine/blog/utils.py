from django.shortcuts import render, get_object_or_404, redirect
from django.urls import reverse
from .models import Post

class ObjectDetailMixin:
    model = None
    template = None

    def get(self, request, slug):
        obj = get_object_or_404(self.model, slug__iexact=slug)
        return render(request, self.template, context={self.model.__name__.lower(): obj, 'admin_object': obj, 'detail':
                                                       True})

class ObjectCreateMixin:
    model = None
    model_form = None
    template = None

    def get(self, request):
        form = self.model_form()
        return render(request, self.template, context={'form': form})

    def post(self, request):
        print("entered first")
        bound_form = self.model_form(request.POST)

        if bound_form.is_valid():
            if self.model == Post:
                print('post model entered')
                post = Post()
                post.user = request.user
                post.title = bound_form.cleaned_data['title']
                post.slug = bound_form.cleaned_data['slug']
                post.body = bound_form.cleaned_data['body']
                post.save()
                post.tags.set(bound_form.cleaned_data['tags'])

                return redirect(post)
            else:
                new_obj = bound_form.save()
                return redirect(new_obj)
        return render(request, self.template, context={'form': bound_form})


class ObjectUpdateMixin:
    model = None
    model_form = None
    template = None

    def get(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        if obj.user == request.user or request.user.is_superuser:
            bound_form = self.model_form(instance=obj)
            return render(request, self.template, context={'form': bound_form, self.model.__name__.lower(): obj})
        else:
            return redirect(obj)


    def post(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        bound_form = self.model_form(request.POST, instance=obj)

        if bound_form.is_valid():
            new_obj = bound_form.save()
            return redirect(new_obj)
        return render(request, self.template, context={'form': bound_form, self.model.__name__.lower(): obj})


class ObjectDeleteMixin:
    model = None
    template = None
    redirect_url = None

    def get(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        if obj.user == request.user or request.user.is_superuser:
            return render(request, self.template, context={self.model.__name__.lower(): obj})
        else:
            return redirect(obj)

    def post(self, request, slug):
        obj = self.model.objects.get(slug__iexact=slug)
        obj.delete()
        return redirect(reverse(self.redirect_url))