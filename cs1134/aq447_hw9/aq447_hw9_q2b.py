import ChainingHashTableMap

#average case runtime: n1 + n2
def intersection_list(lst1, lst2):
    ret = []
    ht = ChainingHashTableMap.ChainingHashTableMap()
    for num1 in lst1:
        ht[num1] = 1
    for num2 in lst2:
        if num2 in ht:
            ret.append(num2)
    return ret
