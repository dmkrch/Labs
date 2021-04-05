from serializer import Serializer

class TomlSerializer(Serializer):
    def greet(cls):
        print("hello from toml")