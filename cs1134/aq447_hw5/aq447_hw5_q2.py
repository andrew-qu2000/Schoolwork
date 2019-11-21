import ArrayStack

class MaxStack:

    def __init__(self):
        self.data_stack = ArrayStack.ArrayStack()
        self.max_val = None

    def __len__(self):
        return len(self.data_stack)

    def is_empty(self):
        return len(self.data_stack) == 0

    def push(self,item):
        elem = (self.max_val,item)
        if self.max_val is None:
            self.max_val = item
        elif self.max_val < item:
            self.max_val = item
        self.data_stack.push(elem)

    def pop(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        else:
            removed_elem = self.data_stack.pop()
            self.max_val = removed_elem[0]
        return removed_elem[1]

    def top(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        else:
            return self.data_stack.top()[1]

    def max(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        else:
            return self.max_val
