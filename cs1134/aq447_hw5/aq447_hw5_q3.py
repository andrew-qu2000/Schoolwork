import ArrayStack
import ArrayDeque

class MidStack:

    def __init__(self):
        self.first_half = ArrayStack.ArrayStack()
        self.second_half = ArrayDeque.ArrayDeque()

    def __len__(self):
        return len(self.first_half) + len(self.second_half)

    def is_empty(self):
        return self.first_half.is_empty() and self.second_half.is_empty()

    def push(self,e):
        if self.first_half.is_empty():
            self.first_half.push(e)
        else:
            if len(self.first_half) == len(self.second_half):
                self.first_half.push(self.second_half.dequeue_first())
            self.second_half.enqueue_last(e)

    def top(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        else:
            if not self.second_half.is_empty():
                return self.second_half.last()
            return self.first_half.top()

    def pop(self):
        if self.is_empty():
            raise Exception("Stack is empty")
        else:
            if len(self.first_half) > len(self.second_half):
                self.second_half.enqueue_first(self.first_half.pop())
            return self.second_half.dequeue_last()
        
    def mid_push(self,e):
        if (not self.first_half.is_empty()) and self.second_half.is_empty():
            self.second_half.enqueue_last(e)
        else:
            self.first_half.push(e)
