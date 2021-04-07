from serializer import Serializer
import json

class JsonSerializer(Serializer):
    
    # function that parses py-obj to json-str
    def parse(obj):
        return json.dumps(obj, default=JsonSerializer.bytes_parse)


    # function that unparses json-str to py-obj
    def unparse(str_data):
        return json.loads(str_data, object_hook=JsonSerializer.bytes_unparse)

    def bytes_parse(obj):
        if isinstance(obj, bytes):
            return {'__class__': 'bytes',
                '__value__': list(obj)}                   
        raise TypeError(repr(obj) + ' is not JSON serializable')   

    def bytes_unparse(str):
        if '__class__' in str:
            if str['__class__'] == 'bytes':
                return bytes(str['__value__'])