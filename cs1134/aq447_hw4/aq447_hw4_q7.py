def split_by_sign(lst,low,high):
    if(low == high):
        return
    if(lst[low] > 0):
        i = low
        while(i < high and lst[i] > 0):
            i += 1
        val = lst[i]
        lst[i] = lst[low]
        lst[low] = val
    split_by_sign(lst,low + 1,high)
