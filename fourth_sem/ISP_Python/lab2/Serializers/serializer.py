class Serializer():
    def serialize(self, obj, fp):
        if obj == "":
            # serializing file
            return self.dump(obj, fp)

        else:
            # serializing obj
            return self.dumps(obj)

    def deserialize(self, obj, fp):
        if obj == "":
            # deserializing file
            return 


    # serializing python object to string
    @classmethod
    def dump(cls, obj, fp):
        myfile = open(fp, mode = 'r', encoding='UTF-8')

        # reading string from file
        data = myfile.read()

        myfile.close()

        # serializing string to obj
        return cls.parse(data)


    # serializing python ojbect to file
    @classmethod
    def dumps(cls, obj):
        return cls.parse(obj)
        pass


    # deserializing python object from file
    @classmethod
    def load(cls, fp):
        pass


    # deserializing python object from string
    @classmethod
    def loads(cls, s):
        pass
            

    # parsing object to string
    # expected to be overrided by derived class
    def parse(str):
        raise Exception("not implemented for abstract Serializer")

    # unparsing string to python object
    # expected to be overrided by derived class
    def unparse():
        pass