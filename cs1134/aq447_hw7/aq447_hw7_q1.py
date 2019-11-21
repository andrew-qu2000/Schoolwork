from LinkedBinaryTree import LinkedBinaryTree

def min_and_max(bin_tree):
    def subtree_min_and_max(subtree_root):
        if subtree_root is None:
            raise Exception("EmptyTree")
        curr_min = subtree_root.data
        curr_max = subtree_root.data
        if subtree_root.left is not None:
            left_side = subtree_min_and_max(subtree_root.left)
            curr_min = min(curr_min,left_side[0])
            curr_max = max(curr_max,left_side[1])
        if subtree_root.right is not None:
            right_side = subtree_min_and_max(subtree_root.right)
            curr_min = min(curr_min,right_side[0])
            curr_max = max(curr_max,right_side[1])
        return (curr_min,curr_max)
    return subtree_min_and_max(bin_tree.root)
