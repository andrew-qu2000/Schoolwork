import random
import UnsortedArrayMap as unsorted_map

class ChainingHashTableMap:
        
    def __init__(self, N=64, p=40206835204840513073):
        self.N = N
        self.table = [unsorted_map.UnsortedArrayMap() for i in range(self.N)]
        self.n = 0
        self.p = p
        self.a = random.randrange(1, self.p - 1)
        self.b = random.randrange(0, self.p - 1)
        self.dll = DoublyLinkedList()

    def hash_function(self, k):
        return ((self.a * hash(k) + self.b) % self.p) % self.N

    def __len__(self):
        return self.n

    def __getitem__(self, key):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        return curr_bucket[key][0]

    def __setitem__(self, key, value):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        if key in curr_bucket:
            node_ref = curr_bucket[key][1]
            curr_bucket[key] = (value,node_ref)
        else:
            self.dll.add_last(key)
            curr_bucket[key] = (value, self.dll.last_node())
            self.n += 1
        '''
        old_size = len(curr_bucket)
        curr_bucket[key] = value
        new_size = len(curr_bucket)
        if (new_size > old_size):
            self.n += 1
        '''
        if (self.n > self.N):
            self.rehash(2 * self.N)

    def __delitem__(self, key):
        i = self.hash_function(key)
        curr_bucket = self.table[i]
        node_to_delete = curr_bucket[key][1]
        self.dll.delete_node(node_to_delete)
        del curr_bucket[key]
        self.n -= 1
        if (self.n < self.N // 4):
            self.rehash(self.N // 2)

    def __iter__(self):
        for key in self.dll:
            yield key
    
    def rehash(self, new_size):
        old = [(key, self[key]) for key in self.dll]
        self.__init__(new_size)
        for (key, val) in old:
            self[key] = val

def print_hash_table(ht):
    for i in range(ht.N):
        print(i, ": ", sep="", end="")
        curr_bucket = ht.table[i]
        for key in curr_bucket:
            print("(", key, ", ", curr_bucket[key], ")", sep="", end="")
        print()

class DoublyLinkedList:
    class Node:
        def __init__(self, data=None, prev=None, next=None):
            self.data = data
            self.prev = prev
            self.next = next

        def disconnect(self):
            self.data = None
            self.prev = None
            self.next = None


    def __init__(self):
        self.header = DoublyLinkedList.Node()
        self.trailer = DoublyLinkedList.Node()
        self.header.next = self.trailer
        self.trailer.prev = self.header
        self.size = 0

    def __len__(self):
        return self.size

    def is_empty(self):
        return len(self) == 0

    def first_node(self):
        if(self.is_empty()):
            raise Exception("List is empty")
        return self.header.next

    def last_node(self):
        if(self.is_empty()):
            raise Exception("List is empty")
        return self.trailer.prev

    def add_after(self, node, data):
        prev = node
        succ = node.next
        new_node = DoublyLinkedList.Node(data, prev, succ)
        prev.next = new_node
        succ.prev = new_node
        self.size += 1
        return new_node

    def add_first(self, data):
        return self.add_after(self.header, data)

    def add_last(self, data):
        return self.add_after(self.trailer.prev, data)

    def add_before(self, node, data):
        return self.add_after(node.prev, data)

    def delete_node(self, node):
        pred = node.prev
        succ = node.next
        pred.next = succ
        succ.prev = pred
        self.size -= 1
        data = node.data
        node.disconnect()
        return data

    def delete_first(self):
        if (self.is_empty()):
            raise Exception("List is empty")
        return self.delete_node(self.first_node())

    def delete_last(self):
        if (self.is_empty()):
            raise Exception("List is empty")
        return self.delete_node(self.last_node())

    def __iter__(self):
        if (self.is_empty()):
            return
        cursor = self.first_node()
        while cursor is not self.trailer:
            yield cursor.data
            cursor = cursor.next

    def __repr__(self):
        return "[" + " <--> ".join([str(item) for item in self]) + "]"
