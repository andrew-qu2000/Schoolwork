def find_duplicates(lst):
    inven = [0] * len(lst)
    for i in lst:
        inven[i] += 1
    return[i for i in range(len(lst)) if inven[i] > 1]
