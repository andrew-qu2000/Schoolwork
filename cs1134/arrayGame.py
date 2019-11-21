def arrayGame(lst):
    ret = False
    maxMoves = lst[0]
    moves = 1
    if(len(lst) == 1):
        ret = True
    while(ret == False and moves <= maxMoves):
        ret = arrayGame(lst[moves:])
        moves += 1
    return ret

A = [3,1,0,1,2,0,1]
print(arrayGame(A))
