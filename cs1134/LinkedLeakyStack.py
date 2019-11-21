import DoublyLinkedList

class LinkedLeakyStack:

    def __init__(self, max_num_of_elems):
        self.data = DoublyLinkedList.DoublyLinkedList()
        self.max_size = max_num_of_elems

    def push(self,e):
        self.data.add_last(e)
        if len(self.data) > self.max_size:
            self.data.delete_first()

    def pop(self):
        if self.data.is_empty():
            raise Exception('LeakyStack is empty')
        return self.data.delete_last()

    def top(self):
        if self.data.is_empty():
            raise Exception('LeakyStack is empty')
        return self.data.last_node().data

    def is_empty(self):
        return self.data.is_empty()

    def __len__(self):
        return len(self.data)
