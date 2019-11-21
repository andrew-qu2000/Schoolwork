def add_binary(num1_str,num2_str):
    total = int(num1_str) + int(num2_str)
    total = ["0"] + list(str(total))
    n = len(total) - 1
    output=""
    while n >= 0:
    	while int(total[n]) > 1:
    		total[n] = int(total[n]) - 2
    		total[n-1] = int(total[n-1]) + 1
    	n -= 1
    for c in total:
    	output += str(c)
    return output
