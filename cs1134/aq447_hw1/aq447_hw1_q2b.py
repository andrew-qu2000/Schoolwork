def shift(lst, k, dirr = 'left'):
    ctr = 0
    while(ctr < k):
        if(dirr == 'left'):
            d = 1
            i = len(lst) - 1
        else:
            d = -1
            i = -1 * len(lst)
        holder1 = 0
        holder2 = lst[i]
        n = 0
        while(n < len(lst)):
            holder1 = lst[i-d]
            lst[i-d] = holder2
            holder2 = holder1
            i -= d
            n += 1
        ctr += 1
