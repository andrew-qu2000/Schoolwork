def eval_postfix_boolean_exp(boolean_exp_str):
    inputs = boolean_exp_str.split()
    stack = []
    for elem in inputs:
        print(stack)
        if elem in "<>&|":
            arg_two = stack.pop()
            arg_one = stack.pop()
            if elem == "<":
                stack.append(arg_one < arg_two)
            elif elem == ">":
                stack.append(arg_one > arg_two)
            elif elem == "&":
                stack.append(arg_one and arg_two)
            else:
                stack.append(arg_one or arg_two)
        else:
            stack.append(elem)
    return stack[0]

exp1 = '5 2 <'
exp2 = '2 5 <'
exp3 = '1 2 < 6 3 < &'
exp4 = '1 2 < 6 3 < |'

print(eval_postfix_boolean_exp(exp1))
print(eval_postfix_boolean_exp(exp2))
print(eval_postfix_boolean_exp(exp3))
print(eval_postfix_boolean_exp(exp4))                
