import BinarySearchTreeMap

def restore_bst(prefix_lst):
    root = restore_bst_helper(prefix_lst,0,len(prefix_lst) - 1)
    ret = BinarySearchTreeMap.BinarySearchTreeMap()
    ret.root = root
    return ret

def restore_bst_helper(prefix_lst,low,high):
    if low > high:
        return None
    else:
        new_ind = low
        while (new_ind <= high) and prefix_lst[low] >= prefix_lst[new_ind]:
            new_ind += 1
        new_item = BinarySearchTreeMap.BinarySearchTreeMap.Item(prefix_lst[low])
        subtree_root = BinarySearchTreeMap.BinarySearchTreeMap.Node(new_item)
        subtree_root.left = restore_bst_helper(prefix_lst,low + 1,new_ind - 1)
        subtree_root.right = restore_bst_helper(prefix_lst,new_ind,high)
        return subtree_root    
