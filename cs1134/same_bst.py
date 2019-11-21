import LinkedBinaryTree

def same_bst(bst1,bst2):
    lst1 = []
    lst2 = []
    for elem in bst1:
        lst1.append(elem.data)
    for elem in bst2:
        lst2.append(elem.data)
    if len(lst1) != len(lst2):
        return False
    else:
        for i in range(len(lst1)):
            if lst[1] != lst[2]:
                return False
        return True
