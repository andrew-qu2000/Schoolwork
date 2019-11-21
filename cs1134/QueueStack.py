import ArrayQueue

class QueueStack:

    def __init__(self):
        self.data = ArrayQueue.ArrayQueue()

    def push(self,e):
        self.data.enqueue(e)

    def pop(self):
        for i in range(1,len(self.data)):
            self.data.enqueue(self.data.dequeue())
        return self.data.dequeue()

    def top(self):
        for i in range(1,len(self.data)):
            self.data.enqueue(self.data.dequeue())
        val = self.data.first()
        self.data.enqueue(self.data.dequeue())
        return val

    def is_empty(self):
        return self.data.is_empty()

    def __len__(self):
        return len(self.data)
