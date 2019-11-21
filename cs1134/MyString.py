import ctypes
def make_array(n):
    return(n * ctypes.py_object)()

class MyString:

    def __init__(self, initial_str = ""):
        cap = 1
        while(cap < len(initial_str)):
            cap *= 2
        self.data = make_array(cap)
        self.n = len(initial_str)
        self.capacity = cap
        for i in range(self.n):
            self.data[i] = initial_str[i]

    def __len__(self):
        return self.n

    def __iter__(self):
        for i in range(self.n):
            yield self.data[i]

    def __repr__(self):
        ret = ""
        for i in range(self.n):
            ret += str(self.data[i])
        return ret

    def __getitem__(self,i):
        if not(0 <= i < self.n):
            raise IndexError("Index out of bounds")
        return self.data[i]

    def __add__(self,other):
        return str(self) + other

    def __radd__(self,other):
        return str(self) + str(other)

    def upper(self):
        ret = ""
        for char in self:
            ret += char.upper()
        return ret

s = "hanoi"
MyS = MyString(s)
print(MyS)
print(MyS + "tower")
print(MyS.upper())
