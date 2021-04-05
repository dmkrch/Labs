from serializer import Serializer

class YamlSerializer(Serializer):
    def greet(cls):
        print("hello from yaml")