def solve_hanoi(n,start,dest,spare):
    if(n == 1):
        print('moving disk from ' + start + ' to ' + dest)
    else:
        solve_hanoi(n-1,start,spare,dest)
        print('moving disk from ' + start + ' to ' + dest)
        solve_hanoi(n-1,spare,dest,start)
        
solve_hanoi(5,'A','C','B')
