def swap(lst,a,b):
    hold = lst[a]
    lst[a] = lst[b]
    lst[b] = hold

def split_parity(lst):
    left = 0
    right = 0
    
    while(right < len(lst)):
        if(lst[right] % 2 == 0):
            right += 1
        else:
            swap(lst,left,right)
            left += 1
            right += 1
