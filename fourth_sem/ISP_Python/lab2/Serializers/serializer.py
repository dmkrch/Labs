class Serializer():
    # ----------------------- SERIALIZATION ----------------------
    def serialize(self, obj, filename="default"):
        if filename != "default":
            return self.dump(obj, filename)
        else:
            return self.dumps(obj)

    # serializing python object to string
    @classmethod
    def dump(cls, obj, filename):
        str_data = cls.parse(obj)
        opened_file = open(filename, mode = 'w', encoding='UTF-8')
        opened_file.write(str_data)
        opened_file.close()

        return str_data

    # serializing python ojbect to file
    @classmethod
    def dumps(cls, obj):
        return cls.parse(obj)

    # parsing object of python to string
    # expected to be overrided by derived class
    def parse(obj):
        raise Exception("parse is not implemented for abstract Serializer")


    # ----------------------- DESERIALIZATION ----------------------
    def deserialize(self, str_data, filename="default"):
        if filename != "default":
            return self.load(filename)
        else:
            return self.loads(str_data)

    # deserializing python object from file
    @classmethod
    def load(cls, filename):
        opened_file = open(filename, mode = 'r', encoding='UTF-8')
        str_data = opened_file.read()
        opened_file.close()

        return cls.unparse(str_data)

    # deserializing python object from string
    @classmethod
    def loads(cls, str_data):
        return cls.unparse(str_data)
            
    # unparsing string to python object
    # expected to be overrided by derived class
    def unparse(str_data):
        raise Exception("unparse is not implemented for abstract Serializer")