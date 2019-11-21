class polynomial:

    def __init__(self, coeff_list = [0]):
        self.coeffs = coeff_list

    def __repr__(self):
        ind = 0
        rtn = ""
        while(ind < len(self.coeffs)):
            c = self.coeffs[ind]
            element = ""
            if(ind != 0):
                if(ind == 1):
                    element += "x"
                else:
                    element += "x^" + str(ind)
            if(c == 0):
                element = ""
            elif(c > 0):
                if(c > 1 or ind == 0):
                    element = str(c) + element
                if(ind < len(self.coeffs) - 1):
                    element = "+" + element
            else:
                if(c < 1 or ind == 0):
                    element = str(c) + element
            rtn = element + rtn
            ind += 1
                
        return rtn

    def eval(self,val):
        rtn = 0.0
        ind = 0
        for c in self.coeffs:
            rtn += c * val ** ind
            ind =+ 1
        return rtn

    def add(self,poly):
        lst1 = self.coeffs
        lst2 = poly.coeffs
        if(len(lst2) > len(lst1)):
            lst1 = poly.coeffs
            lst2 = self.coeffs
        rtn = []
        for e in lst1:
            rtn.append(0)
        ind = 0
        while(ind < len(lst2)):
            rtn[ind] = lst1[ind] + lst2[ind]
            ind += 1
        while(ind < len(lst1)):
            rtn[ind] = lst1[ind]
            ind += 1
        return polynomial(rtn)

    def multiply(self,poly):
        tuples1 = []
        ind = 0
        while(ind < len(self.coeffs)):
            tuples1.append((self.coeffs[ind],ind))
            ind += 1
        tuples2 = []
        ind = 0
        while(ind < len(poly.coeffs)):
            tuples2.append((poly.coeffs[ind],ind))
            ind += 1
        rtn = []
        ln = len(self.coeffs) + len(poly.coeffs) - 1
        i = 0
        while(i < ln):
            rtn.append(0)
            i += 1
        for t in tuples1:
            for T in tuples2:
                rtn[t[1]+T[1]] += t[0] * T[0]
        print(rtn)
        return polynomial(rtn)
    

p1 = polynomial([3,7,1,-9,2])
p2 = polynomial([0,9,0,0,0,0,0,0,0,3])
print(p1.add(p2))
p3 = polynomial([1,1])
p4 = polynomial([2,1])
print(p3)
print(p4)
print(p3.multiply(p4))
p5 = polynomial([0,1,5])
p6 = polynomial([0,1,2,0,0,0,0,0,2])
print(p5)
print(p6)
print(p5.multiply(p6))
