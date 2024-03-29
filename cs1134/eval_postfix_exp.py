import ArrayStack

def eval_postfix_exp(exp_str):
    args_stack = ArrayStack.ArrayStack()
    tokens_list = exp_str.split()
    for token in tokens_list:
        if(token not in '+-*/'):
            args_stack.push(int(token))
        else:
            arg2 = args_stack.pop()
            arg1 = args_stack.pop()
            if(token == '+'):
                res = arg1 + arg2
            elif(token == '-'):
                res = arg1 - arg2
            elif(token == '*'):
                res = arg1 * arg2
            else:
                if(arg2 == 0):
                    raise ZeroDivisionError
                res = arg1 / arg2
            args_stack.push(res)
    return args_stack.pop()

s = '2 3 * 7 +'
print(eval_postfix_exp(s))
