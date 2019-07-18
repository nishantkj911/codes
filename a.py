class myClass:
    def method(self, num):
        assert type(num) == int
        print(num)
        self.method(num)