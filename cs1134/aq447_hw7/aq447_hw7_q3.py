from LinkedBinaryTree import LinkedBinaryTree

def is_height_balanced(bin_tree):
    def is_subtree_height_balanced(subtree_root):
        if subtree_root is None:
            return (True,0)
        else:
            left_side = is_subtree_height_balanced(subtree_root.left)
            right_side = is_subtree_height_balanced(subtree_root.right)
            subtree_root_height = max(left_side[1],right_side[1]) + 1
            subtree_root_balanced = abs(left_side[1] - right_side[1]) <= 1
            children_balanced = left_side[0] and right_side[0]
            return (subtree_root_balanced and children_balanced,subtree_root_height)
    return is_subtree_height_balanced(bin_tree.root)[0]
