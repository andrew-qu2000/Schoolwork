import ArrayStack

variables = {}

def eval_exp(exp_str):
    args_stack = ArrayStack.ArrayStack()
    tokens_list = exp_str.split()
    for token in tokens_list:
        if token in variables:
            args_stack.push(variables[token])
        elif token not in '+-*/':
            args_stack.push(int(token))
        else:
            arg2 = args_stack.pop()
            arg1 = args_stack.pop()
            if token == '+':
                res = arg1 + arg2
            elif token == '-':
                res = arg1 - arg2
            elif token == '*':
                res = arg1 * arg2
            else:
                if arg2 == 0:
                    raise ZeroDivisionError
                else:
                    res = arg1 / arg2
            args_stack.push(res)
    return args_stack.pop()

if __name__ == '__main__':

    flag = True
    while flag:
        
        s = input('--> ');
        if s == 'done()':
            flag = False
        else:
            if '=' in s:
                s = s.split(' = ')
                exp_val = eval_exp(s[1])
                variables[s[0]] = exp_val
                print( s[0] )
            else:
                exp_val = eval_exp(s)
                print( exp_val )

