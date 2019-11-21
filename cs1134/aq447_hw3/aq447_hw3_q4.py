def swap(lst,a,b):
    val = lst[a]
    lst[a] = lst[b]
    lst[b] = val
    
def remove_all(lst,val):
    left = 0
    right = 0
    while(right < len(lst)):
        if(lst[right] != val):
          swap(lst,left,right)
          left += 1
        right += 1
    for i in range(len(lst)-left):
        lst.pop()
