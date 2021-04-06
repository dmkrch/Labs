from serializer import Serializer

import json

class JsonSerializer(Serializer):
    def greet(cls):
        print("hello from json")

    def parse(obj_to_unparse):
        return json.dump(obj)

    def unparse(str_to_unparse):
        return json.load(str_to_unparse)