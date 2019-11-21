from copy import copy

def intersection_list(lst1, lst2):
    srt_lst1 = copy(lst1)
    srt_lst1.sort()
    srt_lst2 = copy(lst2)
    srt_lst2.sort()
    ret = []
    ind1, ind2 = 0, 0
    prev_intersection = None
    while ind1 < len(srt_lst1) and ind2 < len(srt_lst2):
        if srt_lst1[ind1] == srt_lst2[ind2]:
            if srt_lst1[ind1] != prev_intersection:
                ret.append(srt_lst1[ind1])
                prev_intersection = srt_lst1[ind1]
            ind1 += 1
            ind2 += 1
        elif srt_lst1[ind1] < srt_lst2[ind2]:
            ind1 += 1
        else:
            ind2 += 1
    return ret
