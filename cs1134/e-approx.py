def e_approx(n):
    ret = 1
    divisor = 1
    for i in range(1,n+1):
        divisor *= i
        ret += 1/divisor
    return ret

def main():
    for n in range(15):
        curr_approx = e_approx(n)
        approx_str = "{:.15f}".format(curr_approx)
        print("n=", n, "Approximation:", approx_str)

main()
