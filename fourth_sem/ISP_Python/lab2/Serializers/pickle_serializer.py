from serializer import Serializer
import pickle
import codecs

class PickleSerializer(Serializer):

    # function that parses py-obj to pickle-str
    def parse(obj):
        pickled = codecs.encode(pickle.dumps(obj), "base64").decode()
        return pickled


    # function that unparses json-str to py-obj
    def unparse(str_data):
        unpickled = pickle.loads(codecs.decode(str_data.encode(), "base64"))
        return unpickled