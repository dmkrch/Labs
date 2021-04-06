from serializer import Serializer

import json

class JsonSerializer(Serializer):
    
    # function that parses py-obj to json-str
    def parse(obj):
        return json.dumps(obj)


    # function that unparses json-str to py-obj
    def unparse(str_data):
        return json.loads(str_data)