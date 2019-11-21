def list_min(lst,low,high):
    if(low == high):
        return lst[low]
    else:
        if(lst[low] < list_min(lst,low + 1,high)):
           return lst[low]
        else:
           return list_min(lst,low + 1,high)
        
