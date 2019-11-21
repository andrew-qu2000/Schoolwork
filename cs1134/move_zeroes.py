def move_zeroes(nums):
    n = len(nums)
    zeroes = 0
    for k in nums:
        if k == 0:
            zeroes += 1
    index = 0
    for k in nums:
        if k != 0:
            nums[index] = k
            index += 1
    for i in range(n-zeroes,n):
        nums[i] = 0

lst = [1,0,3,0,13]
print(lst)
move_zeroes(lst)
print(lst)
