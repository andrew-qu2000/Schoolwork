import random
import UnsortedArrayMap as unsorted_map

class ChainingHashTableMap:

    def __init__(self, N=64, p=40206835204840513073):
        self.N = N
        self.table = [None for i in range(self.N)]
        self.n = 0
        self.p = p
        self.a = random.randrange(1, self.p - 1)
        self.b = random.randrange(0, self.p - 1)

    def hash_function(self, k):
        return ((self.a * hash(k) + self.b) % self.p) % self.N

    def __len__(self):
        return self.n

    def __getitem__(self, key):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        if curr_bucket is None:
            raise KeyError("Key error: " + str(key) )
        if type(curr_bucket) == unsorted_map.UnsortedArrayMap.Item:
            return curr_bucket.value
        return curr_bucket[key]

    def __setitem__(self, key, value):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        if curr_bucket is None:
            self.table[i] = unsorted_map.UnsortedArrayMap.Item(key,value)
            self.n += 1
        elif type(curr_bucket) == unsorted_map.UnsortedArrayMap.Item:
            if curr_bucket.key == key:
                curr_bucket.value = value
            else:
                new_bucket = unsorted_map.UnsortedArrayMap()
                new_bucket[curr_bucket.key] = curr_bucket.value
                new_bucket[key] = value
                self.n += 1
        else:
            old_size = len(curr_bucket)
            curr_bucket[key] = value
            new_size = len(curr_bucket)
            if (new_size > old_size):
                self.n += 1
        if (self.n > self.N):
            self.rehash(2 * self.N)

    def __delitem__(self, key):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        if curr_bucket is None:
            raise KeyError("Key error: " + str(key) )
        if type(curr_bucket) == unsorted_map.UnsortedArrayMap.Item:
            if curr_bucket.key != key:
                raise KeyError("Key error: " + str(key) )
            self.table[i] = None
            self.n -= 1
        else:
            del curr_bucket[key]
            self.n -= 1
            if len(curr_bucket) == 1:
                self.table[i] = curr_bucket.table[0]
        if (self.n < self.N // 4):
            self.rehash(self.N // 2)

    def __iter__(self):
        for curr_bucket in self.table:
            if curr_bucket is None:
                yield None
            elif type(curr_bucket) == unsorted_map.UnsortedArrayMap.Item:
                yield curr_bucket
            else:
                for key in curr_bucket:
                    yield key

    def rehash(self, new_size):
        old = []
        for key in self:
            if key is not None:
                old.append( (key.key,key.value) )
        self.__init__(new_size)
        for (key, val) in old:
            self[key] = val


def print_hash_table(ht):
    for i in range(ht.N):
        print(i, ": ", sep="", end="")
        curr_bucket = ht.table[i]
        if type(curr_bucket) == unsorted_map.UnsortedArrayMap.Item:
            print("(", curr_bucket.key, ", ", curr_bucket.value, ")", sep="", end="")
        elif type(curr_bucket) == unsorted_map.UnsortedArrayMap:
            for key in curr_bucket:
                print("(", key, ", ", curr_bucket[key], ")", sep="", end="")
        print()

ht = ChainingHashTableMap()
for i in range(100):
    ht[i] = 2*i
print_hash_table(ht)
