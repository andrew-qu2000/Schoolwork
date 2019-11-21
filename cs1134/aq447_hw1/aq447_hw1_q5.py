def fibs(n):
    k1 = 1
    k2 = 1
    count = 0
    while(count < n):
        yield(k1)
        k1 += k2
        count += 1
        if(count < n):
            yield(k2)
            k2 += k1
            count += 1
