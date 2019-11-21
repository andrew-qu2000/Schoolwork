def find_lst_max(lst):
    if(len(lst) == 1):
        return lst[0];
    else:
        return max(lst[0],find_lst_max(lst[1:]));

def max(a,b):
    if(a > b):
        return a;
    return b;

lst = [1,2,3,4,5,100,6,7,8,9]
print(find_lst_max(lst));
