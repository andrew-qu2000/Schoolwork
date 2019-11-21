class ArrayLeakyStack:

    def __init__(self,max_num_of_elems):
        self.data = [None] * max_num_of_elems
        self.front_ind = None
        self.size = 0

    def push(self,e):
        if self.front_ind is None:
            self.front_ind = 0
        self.data[ (self.front_ind + self.size) % len(self.data) ] = e
        self.size += 1
        if self.size > len(self.data):
            self.front_ind = (self.front_ind + 1 ) % len(self.data)
            self.size -= 1

    def pop(self):
        if self.size == 0:
            raise Exception('LeakyStack is empty')
        val = self.data[ (self.front_ind + self.size - 1) % len(self.data) ]
        self.data[ (self.front_ind + self.size - 1) % len(self.data) ] = None
        self.size -= 1
        return val

    def top(self):
        if self.size == 0:
            raise Exception('LeakyStack is empty')
        return self.data[ (self.front_ind + self.size - 1) % len(self.data) ]

    def is_empty(self):
        return self.size == 0

    def __len__(self):
        return self.size

    
        
