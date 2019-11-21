def findChange(lst01):
    left = 0
    right = len(lst01) -1
    ind = 0
    while(left <= right):
        ind = (left + right) // 2
        if(lst01[ind] == 1):
            if(lst01[ind-1] == 0):
                return ind
            else:
                right = ind - 1
        else:
            left = ind + 1
    return ind
