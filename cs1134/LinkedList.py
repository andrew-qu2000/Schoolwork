class LLNode:

    def __init__(self,val = None,next_node = None):
        self._cargo = val
        self._next = next_node

    def getVal(self):
        return self._cargo

    def setVal(self,new_val):
        self._cargo = new_val

    def getNext(self):
        return self._next

    def setNext(self,new_node):
        self._next = new_node

class LinkedList:

    def __init__(self):
        self._head = None
        self._len = 0

    def __len__(self):
        return self._len

    def append(self,val):
        if self._len == 0:
            _head = LLNode(val)
        else:
            end_node = self._head
            while not end_node.getNext() == None:
                end_node = end_node.getNext()
            end_node.setNext(LLNode(val))
            self._len += 1

    def __repr__(self):
        out = '['
        curr_node = self._head
        while not(curr_node.getNext() == None):
            out += str(curr_node.getVal())
            out += ", "
            curr_node = curr_node.getNext()
        return out[:len(out)-2] + ']'
    
ll = LinkedList()
for i in range(10):
    ll.append(i)
print(ll)
