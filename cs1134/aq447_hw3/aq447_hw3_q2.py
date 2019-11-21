import ctypes  # provides low-level arrays
def make_array(n):
    return (n * ctypes.py_object)()

class MyList:
    def __init__(self):
        self.data = make_array(1)
        self.n = 0
        self.capacity = 1

    def __len__(self):
        return self.n

    def append(self, val):
        if (self.n == self.capacity):
            self.resize(2 * self.capacity)
        self.data[self.n] = val
        self.n += 1

    def resize(self, new_capacity):
        new_data = make_array(new_capacity)
        for i in range(self.n):
            new_data[i] = self.data[i]
        self.data = new_data
        self.capacity = new_capacity

    def __getitem__(self, ind):
        if not (-(self.n) <= ind <= (self.n - 1)):
            raise IndexError(str(ind) + " is out of range")
        if(ind > -1):
            return self.data[n]
        else:
            return self.data[self.n + ind]

    def __setitem__(self, ind, value):
        if not (-(self.n) <= ind <= (self.n - 1)):
            raise IndexError(str(ind) + " is out of range")
        if(ind > -1):
            self.data[ind] = value
        else:
            self.data[self.n + ind] = value

    def __iter__(self):
        for i in range(self.n):
            yield self.data[i]

    def extend(self, other):
        for elem in other:
            self.append(elem)

    def __repr__(self):
        ret = MyList()
        for elem in self:
            ret.append(str(elem))     
        return("[" + ",".join(ret) + "]")

    def __add__(self,other):
        ret = MyList()
        ret.resize(self.n+len(other))
        ret.extend(self)
        ret.extend(other)
        return ret

    def __iadd__(self,other):
        ret = self + other
        self.data = ret.data
        self.n = ret.n
        self.capacity = ret.capacity
        
    def __mul__(self,val):
        ret = MyList()
        ret.resize(self.n * val)
        for i in range(val):
            ret.extend(self)
        return ret
    
    def __rmul__(self,val):
        return self * val

    def insert(self, index, val):
        if not(0 <= index < self.n):
            raise IndexError(str(index) + " is out of range")
        if(self.n == self.capacity):
            self.resize(self.capacity * 2)
        for i in range(self.n,index,-1):
            self.data[i] = self.data[i-1]
        self.data[index] = val
        self.n += 1

    def pop(self,index="default"):
        if(self.n < 1):
            raise IndexError()
        if(index == "default"):
            index = self.n - 1
        if not(0 <= index < self.n):
            raise IndexError(str(index) + " is out of range")
        ret = self.data[index]
        for i in range(index,self.n-1):
            self.data[i] = self.data[i+1]
        self.data[self.n-1] = None
        self.n -= 1
        if self.n < self.capacity / 2:
            self.capacity //= 2
        return ret
