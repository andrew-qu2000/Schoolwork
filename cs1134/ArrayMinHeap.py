class ArrayMinHeap:

    class Item:

        def __init__(self, pri, val):
            self.priority = pri
            self.value = val

        def __lt__(self,other):
            return self.priority < other.priority
            
    def __init__(self):
        self.data = [None]

    def __len__(self):
        return len(self.data) - 1

    def is_empty(self):
        return len(self) == 0

    def left(self, ind):
        return 2 * ind

    def right(self, ind):
        return 2 * ind + 1

    def parent(self, ind):
        return ind // 2

    def has_left(self, ind):
        return self.left(ind) <= len(self.data) - 1

    def has_right(self, ind):
        return self.right(ind) <= len(self.data) - 1
    
    def min(self):
        if self.is_empty():
            raise Exception("Priority queue is empty")
        return self.data[1]
    
    def insert(self, pri, val = None):
        new_item = self.Item(pri,val)
        self.data.append( new_item )
        self.fix_up( len( self.data ) - 1 )
        
    def fix_up(self, ind):
        parent_ind = self.parent(ind)
        if ind == 1:
            return
        if self.data[ind] < self.data[parent_ind]:
            swap(ind,parent_ind)
            self.fix_up(parent_ind)

    def fix_down(self, ind):
        if self.has_left(ind) == False and self.has_right(ind) == False:
            return
        elif self.has_left(ind) == True and self.has_right(ind) == False:
            small_child_ind = self.left(ind)
        else:
            left_ind = self.left(ind)
            right_ind = self.right(ind)
            if self.data[left_ind] < self.data[right_ind]:
                small_child_ind = left_ind
            else:
                small_child_ind = right_ind
        if self.data[ind] > self.data[small_child_ind]:
            swap(ind,small_child_ind)
            fix_down(small_child_ind)
    
    def delete_min(self):
        if self.is_empty():
            raise Exception("Priority queue is empty")
        item = self.min()
        self.swap( 1 , len(self.data) - 1 )
        self.data.pop()
        if not self.is_empty():
            self.fix_down(1)
        return item

    def swap(self, i1, i2):
        self.data[i1],self.data[i2] = self.data[i2],self.data[i1]
