def decimal_to_binary(input_int):
    if(input_int == 0):
        return ''
    return decimal_to_binary(input_int // 2) + str(input_int % 2)

for i in range(10):
    print(decimal_to_binary(i))
