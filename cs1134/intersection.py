def intersection(lstA,lstB):
    ret = []
    index = 0
    for k in lstA:
        while index < len(lstB) and k >= lstB[index]:
            if k == lstB[index]:
                ret.append(k)
            index += 1
    return ret

lstA = [1,6,14,19]
lstB = [2,6,12,19,21]
print(intersection(lstA,lstB))
