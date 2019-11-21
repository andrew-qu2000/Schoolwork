def binary_search(srt_lst,val,low,high):
    if(low >= high):
        if(srt_lst[low] == val):
            return low;
        return None
    else:
        i = (low + high) // 2;
        if(srt_lst[i] == val):
            return i;
        elif(srt_lst[i] > val):
            return binary_search(srt_lst,val,low,i - 1);
        else:
            return binary_search(srt_lst,val,i + 1,high);


lst = [0,1,2,3,4,5,6,7,8,9]
for i in range(20):
    print(binary_search(lst,i,0,9));
