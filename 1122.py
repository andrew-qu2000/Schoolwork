def bubble_sort(lst):
	swapped = True
	while (swapped) :
		swapped = False
		for ind in range( len(lst) - 1):
			if lst[ind] > lst[ind+1]:
				lst[ind],lst[ind+1] = lst[ind+1],lst[ind]
				swapped = True

lst = [4,7,3,2,6,9,4]
bubble_sort(lst
