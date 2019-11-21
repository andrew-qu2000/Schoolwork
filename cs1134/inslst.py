def inslst(lst):
    length = 0
    origlen = len(lst)
    while length < (origlen * 2):
        square = lst[length] ** 2
        length += 1
        print(length, square)
        lst.insert(length, square)
        length += 1

lst = [1,1,1,1,1,1,1,1,1,1]
lst2 = [0,1,2,3,4,5,6,7,8,9]

inslst(lst)
print()
print(lst)
print()
inslst(lst2)
print()
print(lst2)
