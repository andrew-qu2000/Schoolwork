import random
import UnsortedArrayMap

class HashTableMap:

    def __init__(self, N = 2, p = 40206835204840513073):
        self.N = N
        self.n = 0
        self.table = [UnsortedArrayMap.UnsortedArrayMap() for i in range(N)]
        self.p = p
        self.a = random.randrange(1, self.p - 1)
        self.b = random.randrange(0, self.p - 1)

    def hash_function(self, key):
        return ( (self.a * hash(key) + b) % self.p ) % self.N
    
    def __len__(self):
        return self.n

    def is_empty(self):
        return (len(self) == 0)

    def __getitem__(self, key):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        return curr_bucket[key]

    def __setitem__(self, key, value):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        old_size = len( curr_bucket )
        curr_bucket[key] = value
        new_size = len( curr_bucket )
        if new_size > old_size:
            self.n += 1
        if self.n > self.N:
            self.rehash( self.N * 2 )

    def __delitem__(self, key):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        del curr_bucket[key]
        self.n -= 1
        if self.n < self.N / 2:
            self.rehash( self.N / 2 )

    def __iter__(self):
        for bucket in self.table:
            for key in bucket:
                yield key
    
    def rehash(self, new_size):
        old = [(key, self[key]) for key in self]
        self.__init__(new_size)
        for (key, val) in old:
            self[key] = val

        
    
