from Serializers.serializer import Serializer
from factory import Factory
import argparse

# -----------------------------argparse module----------------------------
parser = argparse.ArgumentParser()
parser.add_argument("--path", type=str, help="enter path to file")
parser.add_argument("--format", type=str, help="enter format to convert")
args = parser.parse_args()
file_path = getattr(args, 'path')
new_format_type = getattr(args, 'format')

# --------------------------- UTILITY WORK ------------------------------

#our utility doing:
# 1. first we need to deserialize our data from given path_file to py obj
# 2. then we need to serialize it to new file with new_format_type


str_parts = file_path.split(".")
initial_format_type = str_parts[1]
serializer = Factory.create_serializer(initial_format_type)
py_obj = serializer.deserialize("", file_path)

serializer = Factory.create_serializer(new_format_type)

new_file_name = str_parts[0] + "." + new_format_type
serializer.serialize(py_obj, new_file_name)