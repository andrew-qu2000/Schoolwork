from LinkedBinaryTree import LinkedBinaryTree

def create_expression_tree(prefix_exp_str):
    tokens_list = prefix_exp_str.split()
    def create_expression_tree_helper(prefix_exp,start_pos):

        root = LinkedBinaryTree.Node(prefix_exp[start_pos])
        size = 1
        if prefix_exp[start_pos + size] in '+-*/':
            left_side = create_expression_tree_helper(prefix_exp,start_pos + size)
            root.left = left_side[0].root
            size += left_side[1]
        else:
            token_int = int(prefix_exp[start_pos + size])
            root.left = LinkedBinaryTree.Node(token_int)
            size += 1
        if prefix_exp[start_pos + size] in '+-*/':
            right_side = create_expression_tree_helper(prefix_exp,start_pos + size)
            root.right = right_side[0].root
            size += right_side[1]
        else:
            token_int = int(prefix_exp[start_pos + size])
            root.right = LinkedBinaryTree.Node(token_int)
            size += 1
        return ( LinkedBinaryTree(root) , size )
        
    return create_expression_tree_helper(tokens_list,0)[0]

def prefix_to_postfix(prefix_exp_str):
    lbt = create_expression_tree(prefix_exp_str)
    lst = [str(node.data) for node in lbt.postorder()]
    return ' '.join(lst)
