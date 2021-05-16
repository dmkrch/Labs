from Serializers.serializer import Serializer
from factory import Factory
import argparse
from Tests.test_classes import *
import cloudpickle
import pickle

def main():
    # ----------------------------- ARGPARSE ----------------------------

    parser = argparse.ArgumentParser()
    parser.add_argument("--path", type=str, help="enter path to file")
    parser.add_argument("--format", type=str, help="enter format to convert")
    args = parser.parse_args()
    file_path = getattr(args, 'path')
    new_format_type = getattr(args, 'format')

    print(file_path)
    print(new_format_type)

    # --------------------------- UTILITY WORK ------------------------------

    str_parts = file_path.split(".")
    initial_format_type = str_parts[1]
    serializer = Factory.create_serializer(initial_format_type)
    py_obj = serializer.deserialize("", file_path)

    serializer = Factory.create_serializer(new_format_type)

    new_file_name = str_parts[0] + "." + new_format_type
    serializer.serialize(py_obj, new_file_name)

if __name__ == '__main__':
    exit(main())

# add_one = lambda x: x + 1

# s = Factory.create_serializer("json")
# json_str = s.serialize(lambda x: x + 1, "data1.json")
# lambda_new = s.deserialize(json_str,)

# print(lambda_new(5))

# s = Factory.create_serializer("json")
# new_class = s.deserialize("", "test_class.json")
# obj1 = new_class(25, "Male")

# print(obj1.get_age())