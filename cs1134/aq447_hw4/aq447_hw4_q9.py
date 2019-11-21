def permutations(lst,low,high):
    ret = []
    if(low == high):
        ret.append([lst[low]])
    else:
        for perm in permutations(lst,low+1,high):
            for i in range(len(perm) + 1):
                newPerm = perm.copy()
                newPerm.insert(i,lst[low])
                ret.append(newPerm)
    return ret    
