import BinarySearchTreeMap

def create_chain_bst(n):
    chain_bst = BinarySearchTreeMap.BinarySearchTreeMap()
    for i in range(1,n+1):
        chain_bst.insert(i)
    return chain_bst

def create_complete_bst(n):
    bst = BinarySearchTreeMap.BinarySearchTreeMap()
    add_items(bst, 1, n)
    return bst

def add_items(bst, low, high):
    if low == high:
        bst.insert(low)
    else:
        subtree_root = low + (high - low) // 2
        bst.insert(subtree_root)
        add_items(bst,low,subtree_root - 1)
        add_items(bst,subtree_root + 1,high)
