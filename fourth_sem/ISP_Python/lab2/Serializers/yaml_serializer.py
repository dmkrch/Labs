from Serializers.serializer import Serializer
import yaml

class YamlSerializer(Serializer):

    # function that parses py-obj to json-str
    def parse(obj):
        return yaml.dump(obj)

    # function that unparses json-str to py-obj
    def unparse(str_data):
        return yaml.load(str_data, Loader=yaml.FullLoader)