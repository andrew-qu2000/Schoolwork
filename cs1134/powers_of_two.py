def powers_of_two(num):
    for i in range(1,num+1):
        yield 2**i

for curr_value in powers_of_two(100):
    print(curr_value)
