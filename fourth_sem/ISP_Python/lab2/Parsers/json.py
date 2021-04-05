from serializer import Serializer

class JsonSerializer(Serializer):
    def greet(cls):
        print("hello from json")