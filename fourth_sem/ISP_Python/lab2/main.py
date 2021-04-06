import sys
sys.path.insert(0, 'Serializers')
from serializer import Serializer
from factory import Factory

class Human():
    def __init__(self, age, gender):
        self._age = age
        self._gender = gender

    def get_age(self):
        return self._age

    def get_gender(self):
        return self._gender

    def __str__(self):
        return (f"{self._age}, {self._gender}")



class Student():
    def __init__(self, name, date, hm):
        self._name = name
        self._date = date
        self._arr = list(range(10))
        self._human = hm

    def get_name(self):
        return self._name

    def get_date(self):
        return self._date

    def get_human(self):
        return self._human

    def print_st_info(self):
        print(f"name: {self._name}, date: {self._date}, arr: {self._arr}, human: {self._human}")


hm1 = Human(20, "Male")
st1 = Student("Vasya Pupkin", "01.02.1000", hm1)

serializer = Factory.create_serializer("json")
serializer.greet()

str_obj = serializer.serialize("", "serialize-test.txt")
print(str_obj)