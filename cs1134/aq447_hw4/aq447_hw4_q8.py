def flat_list(nested_lst,low,high):
    ret = []
    if(low == high):
        if(isinstance(nested_lst[low],int)):
            ret.append(nested_lst[low])
        else:
            for elem in flat_list(nested_lst[low],0,len(nested_lst[low]) - 1):
                ret.append(elem)
    else:
        if isinstance(nested_lst[low],int):
            ret.append(nested_lst[low])
        else:
            for elem in flat_list(nested_lst[low],0,len(nested_lst[low]) - 1):
                ret.append(elem)
        for elem in flat_list(nested_lst,low + 1,high):
            ret.append(elem)
    return ret
