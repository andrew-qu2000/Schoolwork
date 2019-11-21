def factors(num):
    i = 1
    while(i*i <= num):
        if(num % i == 0):
            yield i
        i += 1
    i -= 1
    if(num // i == i): #square
        i -= 1
    while(i > 0):
        if(num % i == 0):
            yield num//i # single / yields a float, even if it divides cleanly
        i -= 1
