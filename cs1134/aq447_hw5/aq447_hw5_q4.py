import ArrayStack

class Queue:

    def __init__(self):
        self.forward_stack = ArrayStack.ArrayStack()
        self.backward_stack = ArrayStack.ArrayStack()

    def __len__(self):
        return (len(self.forward_stack) + len(self.backward_stack))

    def is_empty(self):
        return len(self) == 0

    def enqueue(self,item):
        self.forward_stack.push(item)

    def dequeue(self):
        if len(self) == 0:
            raise Exception("Queue is empty")
        else:
            if self.backward_stack.is_empty():
                while not self.forward_stack.is_empty():
                    self.backward_stack.push(self.forward_stack.pop())
            return self.backward_stack.pop()

    def first(self):
        if len(self) == 0:
            raise Exception("Queue is empty")
        else:
            if self.backward_stack.is_empty():
                while not self.forward_stack.is_empty():
                    self.backward_stack.push(self.forward_stack.pop())
            return self.backward_stack.top()
