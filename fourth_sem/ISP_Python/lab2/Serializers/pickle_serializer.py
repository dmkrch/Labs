from serializer import Serializer

class PickleSerializer(Serializer):
    def greet(cls):
        print("hello from toml")