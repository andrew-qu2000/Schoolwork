import BinarySearchTreeMap

def find_min_abs_difference(bst):
    return fmad_helper( bst.root )[2]

def fmad_helper(subtree_root):
    subtree_min = subtree_root.item.key
    subtree_max = subtree_root.item.key
    min_diff = None
    if subtree_root.left is not None:
        left_side = fmad_helper(subtree_root.left)
        subtree_min = left_side[0]
        if left_side[2] is None:
            min_diff = subtree_root.item.key - left_side[1]
        else:
            min_diff = min( subtree_root.item.key - left_side[1] , left_side[2] )
    if subtree_root.right is not None:
        right_side = fmad_helper(subtree_root.right)
        subtree_max = right_side[1]
        if min_diff is not None:
            min_diff = min( min_diff , right_side[0] - subtree_root.item.key )
        if right_side[2] is not None:
            min_diff = min( min_diff , right_side[2] )
        if min_diff is None:
            min_diff = right_side[0] - subtree_root.item.key
    return (subtree_min,subtree_max,min_diff)
