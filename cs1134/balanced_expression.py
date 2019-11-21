def balanced_expression(string_input):
    bracketLst = []
    for char in string_input:
        if char in "([{":
            bracketLst.append(char)
        else:
            if char == ")":
                if bracketLst[len(bracketLst) - 1] == "(":
                    bracketLst.pop()
                else:
                    return False
            elif char == "]":
                if bracketLst[len(bracketLst) - 1] == "[":
                    bracketLst.pop()
                else:
                    return False
            else:
                if bracketLst[len(bracketLst) - 1] == "{":
                    bracketLst.pop()
                else:
                    return False
    return len(bracketLst) == 0

s1 = "{{([])}}([])"
s2 = "{{[(])}}"

print (balanced_expression(s1))
print (balanced_expression(s2))
