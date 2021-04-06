import sys
sys.path.insert(0, 'Serializers')

from yaml_serializer import YamlSerializer
from pickle_serializer import PickleSerializer
from json_serializer import JsonSerializer
from toml_serializer import TomlSerializer

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