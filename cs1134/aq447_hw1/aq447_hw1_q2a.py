def shift(lst, k):
    ctr = 0
    while(ctr < k):
        i = len(lst) - 1
        holder1 = 0
        holder2 = lst[i]
        n = 0
        while(n < len(lst)):
            holder1 = lst[i-1]
            lst[i-1] = holder2
            holder2 = holder1
            i -= 1
            n += 1
        ctr += 1
        
        
