def sumNSquares(n):
    rtn = 0
    for k in range(1,n):
        rtn += k*k
    return rtn

sum([k*k for k in range(1,n)])

def sumOddNSquares(n):
    trn = 0
    for k in range(1,n):
        if(k % 2 != 0):
            rtn += k*k
    return rtn

sum([k*k for k in range(1,n) if k % 2 != 0])
