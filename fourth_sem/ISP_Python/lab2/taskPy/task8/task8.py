def cached(func):
    cache = dict()

    def wrapper(*args):
        if args in cache:
            return cache[args]
        result = func(*args)
        cache[args] = result
        return result

    return wrapper


@cached
def fib(n):
    if n in (0, 1):
        return n
    return fib(n - 1) + fib(n - 2)


if __name__ == '__main__':
    print(fib(40))