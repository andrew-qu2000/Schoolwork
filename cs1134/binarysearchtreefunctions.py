class Node:
    def number_of_children(self):
        count = 0
        if self.left is not None:
            count += 1
        if self.right is not None:
            count += 1
        return count
    def disconnect(self):
        self.item = None
        self.left = None
        self.right = None
        self.parent = None

def __delitem__(self, key):
    node = self.find(key)
    if node is not None:
        self.delete_node(node)
    else:
        raise KeyError(str(key) + " is not found")

def delete_node(self, node_to_delete):
    item = node_to_delete.item
    num_children = node_to_delete.number_of_children()
    if node_to_delete is self.root:
        if num_children == 0:
            self.root = None
            self.size -= 1
            node_to_delete.disconnect()
        elif num_children == 1:
            if node_to_delete.left is not None:
                self.root = node_to_delete.left
            else:
                self.root = node_to_delete.right
            self.root.parent = None
            self.size -= 1
            node_to_delete.disconnect()
        else:
            
            
    else:       
        if num_children == 0:
            parent = node_to_delete.parent
            if parent.left is node_to_delete:
                parent.left = None
            else:
                parent.right = None
            self.size -= 1
            node_to_delete.disconnect()
        elif num_children == 1:
            parent = node_to_delete.parent
            if node_to_delete.left is not None:
                child = node.left
            else:
                child = node.right
            if parent.left is node_to_delete:
                parent.left = child
            else:
                parent.right = child
            child.parent = parent
            size -= 1
            node_to_delete.disconnect()
        else:
            parent = node_to_delete.parent
            
    return item

def subtree_max(subtree_root):
    curr_node = subtree_root
    while curr_node.right is not None:
        curr_node = curr_node.right
    return curr_node
