class Vector:

    def __init__(self, d):
        if (isinstance(d,int)):
            self.coords = [0]*d
        else:
            self.coords = d

    def __len__(self):
        return len(self.coords)

    def __getitem__(self, j):
        return self.coords[j]

    def __setitem__(self, j, val):
        self.coords[j] = val

    def __add__(self, other):
        if (len(self) != len(other)):
            raise ValueError("dimensions must agree")
        result = Vector(len(self))
        for j in range(len(self)):
            result[j] = self[j] + other[j]
        return result
    
    def __sub__(self, other):
        if (len(self) != len(other)):
            raise ValueError("dimensions must agree")
        result = Vector(len(self))
        for j in range(len(self)):
            result[j] = self[j] - other[j]
        return result
    def __neg__(self):
        rtn = [0]*len(self.coords)
        for j in range(len(self.coords)):
            rtn[j] = -1 * self.coords[j]
        return rtn

    def __mul__(self,m):
        if (isinstance(m,int)):
            rtn = Vector(len(self.coords))
            for j in range(len(self.coords)):
                rtn[j] = self.coords[j] * m
            return rtn
        else:
            rtn = 0
            for j in range(len(self.coords)):
                rtn += self.coords[j] * m.coords[j]
            return rtn

    def __rmul__(self,m):
        rtn = Vector(len(self.coords))
        for j in range(len(self.coords)):
            rtn[j] = self.coords[j] * m
        return rtn
            
    def __eq__(self, other):
        return self.coords == other.coords

    def __ne__(self, other):
        return not (self == other)

    def __str__(self):
        return '<' + str(self.coords)[1:-1] + '>'

    def __repr__(self):
        return str(self)
