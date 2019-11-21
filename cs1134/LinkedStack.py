import DoublyLinkedList

class LinkedStack:
        
    def __init__(self):
        self.data = DoublyLinkedList.DoublyLinkedList()

    def push(self, e):
        self.data.add_last(e)

    def pop(self):
        return self.data.delete_last()

    def top(self):
        return self.data.last_node().data

    def is_empty(self):
        return self.data.is_empty()

    def __len__(self):
        return len(self.data)
