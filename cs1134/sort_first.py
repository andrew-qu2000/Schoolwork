def sort_first(lst):
    first = lst[0]
    low = 1
    high = 1
    count = 0
    while(high < len(lst)): #n
        if(lst[high] > first):
            high += 1
        else:
            lst[low],lst[high] = lst[high],lst[low]
            low += 1
            high += 1
            count += 1
    lst.remove(first) #n
    lst.insert(count,first) #n
