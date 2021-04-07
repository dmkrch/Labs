import sys
sys.path.insert(0, 'Serializers')
from serializer import Serializer
from factory import Factory
import pickle
import argparse
from test_classes import Human, Student,SomeFunction, TestClass, age1
import toml

hm1 = Human(20, "Male")
st1 = Student("Vasya Pupkin", "01.02.2000", hm1)
hm2 = { "Name": "Dmitry", "Age": 25}

test_human = {"Name": "Dmitry", "Age": 25, "Date": "25.05.2000" }

# --------------------------------------------argparse module
# parser = argparse.ArgumentParser()
# parser.add_argument("--path", type=str, help="enter path to file")
# parser.add_argument("--format", type=str, help="enter format to convert")
# args = parser.parse_args()
# file_path = getattr(args, 'path')
# new_format_type = getattr(args, 'format')
# print("file path: " + file_path + " format: " + new_format_type)



# --------------------------- SERIALIZE TEST ------------------------------
serializer = Factory.create_serializer("pickle")
pickle_obj = serializer.serialize(SomeFunction)
print(pickle_obj)

new_func = serializer.deserialize(pickle_obj)
new_func(50)