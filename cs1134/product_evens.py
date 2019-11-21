def product_evens(n):
    if(n % 2 != 0):
        n -= 1;
    if(n == 0):
        return 0;
    if(n == 2):
        return 2;
    else:
        return n * product_evens(n-2);

for i in range(10):
    print("n= " + str(i) + " product_evens= " + str(product_evens(i)));
