class ArrayDeque:

    INITIAL_CAPACITY = 8

    def __init__(self):
        self.data = [None] * ArrayDeque.INITIAL_CAPACITY
        self.num_of_elems = 0
        self.front_ind = None
        #self.back_ind = None

    def __len__(self):
        return self.num_of_elems

    def is_empty(self):
        return self.num_of_elems == 0

    def first(self):
        if self.num_of_elems == 0:
            raise Exception("Deque is empty")
        return self.data[self.front_ind]

    def last(self):
        if self.num_of_elems == 0:
            raise Exception("Deque is empty")
        return self.data[self.front_ind + self.num_of_elems - 1]

    def enqueue_first(self,elem):
        if self.num_of_elems == len(self.data):
            self.resize(len(self.data) * 2)
        if self.num_of_elems == 0:
            self.data[0] = elem
            self.front_ind = 0
            self.num_of_elems += 1
        else:
            self.front_ind -= 1
            self.data[self.front_ind] = elem
            self.num_of_elems += 1

    def enqueue_last(self,elem):
        if self.num_of_elems == len(self.data):
            self.resize(len(self.data) * 2)
        if self.num_of_elems == 0:
            self.data[0] = elem
            self.front_ind = 0
            self.num_of_elems += 1
        else:
            back_ind = (self.front_ind + self.num_of_elems) % len(self.data)
            self.data[back_ind] = elem
            self.num_of_elems += 1

    def dequeue_first(self,elem):
        if self.num_of_elems == 0:
            raise Exception("Deque is empty")
        ret = self.data[self.front_ind]
        self.data[self.front_ind] = None
        self.front_ind = (self.front_ind + 1) % len(self.data)
        self.num_of_elems -= 1
        if self.num_of_elems == 0:
            self.front_ind = None
        elif self.num_of_elems < len(self.data) // 4:
            self.resize(len(self.data) // 2)
        return ret

    def dequeue_last(self,elem):
        if self.num_of_elems == 0:
            raise Exception("Deque is empty")
        back_ind = (self.front_ind + self.num_of_elems - 1) % len(self.data)
        ret = self.data[back_ind]
        self.data[back_ind] = None
        self.num_of_elems -= 1
        if self.num_of_elems == 0:
            self.front_ind = None
        elif self.num_of_elems < len(self.data) // 4:
            self.resize(len(self.data) // 2)
        return ret

    def resize(self,new_cap):
        old_data = self.data
        self.data = [None] * new_cap
        old_ind = self.front_ind
        for new_ind in range(self.num_of_elems):
            self.data[new_ind] = old_data[old_ind]
            old_ind = (old_ind + 1) % len(old_data)
        self.front_ind = 0
