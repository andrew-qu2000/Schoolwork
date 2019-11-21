def nested_sum(lst):
    ret = 0;
    if(len(lst) <= 0):
        return 0;
    try:
        ret += lst[0];
    except:
        ret += nested_sum(lst[0]);
    return ret + nested_sum(lst[1:]);

lst = [[1,2],[3,[[4],5]],6];
print (nested_sum(lst));
