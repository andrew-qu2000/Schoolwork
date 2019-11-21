from ArrayMinHeap import ArrayMinHeap

class ArrayMinHeapQueue:

    def __init__(self):
        self.amh = ArrayMinHeap()
        self.max_pri = 0

    def __len__(self):
        return len(self.amh)

    def is_empty(self):
        return self.amh.is_empty()
    
    def enqueue(self,elem):
        self.amh.insert( self.max_pri + 1 , elem )
        self.max_pri += 1

    def dequeue(self):
        if self.amh.is_empty():
            raise Exception("FIFO Queue is empty")
        return self.amh.delete_min().value

    def first():
        if self.amh.is_empty():
            raise Exception("FIFO Queue is empty")
        return self.amh.min().value

amhq = ArrayMinHeapQueue()
amhq.enqueue('the')
amhq.enqueue('cat')
amhq.enqueue('in')
amhq.enqueue('the')
amhq.enqueue('hat')
