import DoublyLinkedList

class Integer:

    def __init__(self, num_str):
        self.data = DoublyLinkedList.DoublyLinkedList()
        ind = 0
        while num_str[ind] == '0' and ind < (len(num_str) - 1): #ignore nonsignificant zeroes
            ind += 1
        for i in range(ind,len(num_str)):
            self.data.add_last(int(num_str[i]))
        #for char in num_str:
         #   self.data.add_last(int(char))

    def __add__(self,other):
        ret = ""
        if not self.data.is_empty():
            self_parser = self.data.last_node()
        if not other.data.is_empty():
            other_parser = other.data.last_node()
        dig_val = 0
        while not((self_parser.data is None) and (other_parser.data is None)):
            if self_parser.data is not None:
                dig_val += self_parser.data
                self_parser = self_parser.prev
            if other_parser.data is not None:
                dig_val += other_parser.data
                other_parser = other_parser.prev
            ret = str(dig_val % 10) + ret
            dig_val //= 10
        if dig_val != 0:
            ret = str(dig_val) + ret
        return Integer(ret)

    def __mul__(self,other):
        ret = ''
        subproducts = []
        if not self.data.is_empty():
            self_parser = self.data.last_node()
        if not other.data.is_empty():
            other_parser = other.data.last_node()
        count = 0
        while not other_parser.data is None:
            subproduct =''
            dig_val = 0
            while not self_parser.data is None:
                dig_val += other_parser.data * self_parser.data
                subproduct = str(dig_val % 10) + subproduct
                dig_val //= 10
                self_parser = self_parser.prev
            subproduct += '0' * count
            if dig_val != 0:
                subproduct = str(dig_val) + subproduct
            subproducts.append(subproduct)
            count += 1
            other_parser = other_parser.prev
            self_parser = self.data.last_node()
        dig_val = 0
        count = 1
        for i in range(len(subproducts[-1])):
            for sub in subproducts:
                if len(sub) - count >= 0:
                    dig_val += int(sub[len(sub) - count])
            ret = str(dig_val % 10) + ret
            dig_val //= 10
            count += 1
        if dig_val != 0:
            ret = str(dig_val) + ret
        return Integer(ret)
        
                
    def __repr__(self):
        ret = ""
        for elem in self.data:
            ret += str(elem)
        return ret
