class MyClass:
    c = ""
    d = 0
    def __init__(self, a, b):
        assert type(a) == str
        assert type(b) == int
        self.c = a
        self.d = b

    def myMethod(self, a, b):
        return pow(a, b)

obj = MyClass()