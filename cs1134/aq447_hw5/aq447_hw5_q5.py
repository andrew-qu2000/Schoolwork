import ArrayQueue
import ArrayStack

def permutations(lst):

    stack = ArrayStack.ArrayStack()
    ret_queue = ArrayQueue.ArrayQueue()
    
    for elem in lst:
        stack.push(elem)
        
    while not stack.is_empty():
        
        curr_elem = stack.pop()
        
        if ret_queue.is_empty():
            ret_queue.enqueue([curr_elem])
            
        else:
            while(len(ret_queue.first()) < len(lst) - len(stack)):
                
                curr_insert_spot = 0
                max_insert_spot = len(ret_queue.first())
                    
                while curr_insert_spot <= max_insert_spot:
                    
                    new_perm = []
                    for elem in ret_queue.first():
                        new_perm.append(elem)
                    new_perm.insert(curr_insert_spot,curr_elem)
                    ret_queue.enqueue(new_perm)
                    curr_insert_spot += 1
                    
                ret_queue.dequeue()
    ret_lst = []
    while not ret_queue.is_empty():
        ret_lst.append(ret_queue.dequeue())
    return ret_lst
