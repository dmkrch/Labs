from django.test import TestCase, Client
from django.urls import reverse
from blog.models import *
import json


class TestViews(TestCase):
    def setUp(self):
        self.client = Client()
        self.posts_list_url = reverse('posts_list_url')

    def test_post_detail_view_GET(self):
        response = self.client.get(self.posts_list_url)
        self.assertEquals(response.status_code, 200)
        self.assertTemplateUsed(response, 'blog/index.html')

    def test_post_detail_view_POST(self):
        client = Client()
