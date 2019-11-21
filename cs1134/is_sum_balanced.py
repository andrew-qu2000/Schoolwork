import LinkedBinaryTree

def is_sum_balanced(bin_tree):
    def is_subtree_sum_balanced(subtree_root):
        if subtree_root is None:
            return True
        else:
            balanced = abs(subtree_root.left - subtree_root.right) <= 1
            return balanced and is_subtree_sum_balanced(subtree.root.left) and is_subtree_sum_balanced(subtree_root.right)
    return is_subtree_sum_balanced(bin_tree.root)
