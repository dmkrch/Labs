import sys

sys.path.insert(0, 'Parsers')

from yaml import YamlSerializer
from pickle import PickleSerializer
from json import JsonSerializer
from toml import TomlSerializer

class Factory():
    @staticmethod
    def create_serializer(s_name):
        if (s_name == "json"):
            return JsonSerializer()
        elif (s_name == "pickle"):
            return PickleSerializer()
        elif (s_name == "yaml"):
            return YamlSerializer()
        elif (s_name == "toml"):
            return TomlSerializer()
        else:
            raise Exception("No such parsers")
        

    @staticmethod
    def do():
        print("asfdsdaf")