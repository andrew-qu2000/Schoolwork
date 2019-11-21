import ArrayQueue

class LinkedBinaryTree:

    class Node:
        def __init__(self, data, left=None, right=None):
            self.data = data
            self.parent = None
            self.left = left
            if (self.left is not None):
                self.left.parent = self
            self.right = right
            if (self.right is not None):
                self.right.parent = self

    def __init__(self, root=None):
        self.root = root
        self.size = self.subtree_count(root)

    def __len__(self):
        return self.size

    def is_empty(self):
        return len(self) == 0

    def subtree_count(self, subtree_root):
        if (subtree_root is None):
            return 0
        else:
            left_count = self.subtree_count(subtree_root.left)
            right_count = self.subtree_count(subtree_root.right)
            return 1 + left_count + right_count


    def sum(self):
        return self.subtree_sum(self.root)

    def subtree_sum(self, subtree_root):
        if (subtree_root is None):
            return 0
        else:
            left_sum = self.subtree_sum(subtree_root.left)
            right_sum = self.subtree_sum(subtree_root.right)
            return subtree_root.data + left_sum + right_sum


    def height(self):
        if(self.is_empty()):
            raise Exception("Height is not defined for an empty tree")
        return self.subtree_height(self.root)

    def subtree_height(self, subtree_root):
        if ((subtree_root.left is None) and (subtree_root.right is None)):
            return 0
        elif ((subtree_root.left is not None) and (subtree_root.right is None)):
            return 1 + self.subtree_height(subtree_root.left)
        elif ((subtree_root.left is None) and (subtree_root.right is not None)):
            return 1 + self.subtree_height(subtree_root.right)
        else:
            left_height = self.subtree_height(subtree_root.left)
            right_height = self.subtree_height(subtree_root.right)
            return 1 + max(left_height, right_height)


    def preorder(self):
        yield from self.subtree_preorder(self.root)

    def subtree_preorder(self, curr_root):
        if(curr_root is None):
            pass
        else:
            yield curr_root
            yield from self.subtree_preorder(curr_root.left)
            yield from self.subtree_preorder(curr_root.right)


    def postorder(self):
        yield from self.subtree_postorder(self.root)

    def subtree_postorder(self, curr_root):
        if(curr_root is None):
            pass
        else:
            yield from self.subtree_postorder(curr_root.left)
            yield from self.subtree_postorder(curr_root.right)
            yield curr_root


    def inorder(self):
        yield from self.subtree_inorder(self.root)

    def subtree_inorder(self, curr_root):
        if(curr_root is None):
            pass
        else:
            yield from self.subtree_inorder(curr_root.left)
            yield curr_root
            yield from self.subtree_inorder(curr_root.right)


    def breadth_first(self):
        if (self.is_empty()):
            return
        line = ArrayQueue.ArrayQueue()
        line.enqueue(self.root)
        while (line.is_empty() == False):
            curr_node = line.dequeue()
            yield curr_node
            if (curr_node.left is not None):
                line.enqueue(curr_node.left)
            if (curr_node.right is not None):
                line.enqueue(curr_node.right)

    def subtree_children_dist(self, curr_root):
        ret = [1,0,0]
        
        if curr_root.left is not None:
            ret = [0,1,0]
            
            left_stats = self.subtree_children_dist(curr_root.left)
            for i in range(3):
                ret[i] += left_stats[i]
                
        if curr_root.right is not None:
            
            if curr_root.left is None:
                ret = [0,1,0]
            else:
                ret[1] -= 1
                ret[2] += 1
                
            right_stats = self.subtree_children_dist(curr_root.right)
            for i in range(3):
                ret[i] += right_stats[i]
                
        return ret

    def leaves_list(self):
        return [leaf for leaf in self.subtree_leaves_list(self.root)]

    def subtree_leaves_list(self, curr_root):
        if curr_root is None:
            pass
        elif curr_root.left is None and curr_root.right is None:
            yield curr_root.data
        else:
            yield from self.subtree_leaves_list(curr_root.left)
            yield from self.subtree_leaves_list(curr_root.right)

    def iterative_inorder(self):
        curr_node = self.root
        parent_node = None
        if curr_node is None:
            return
        while curr_node.left is not None:
            parent_node = curr_node
            curr_node = curr_node.left
        final_node = self.root
        while final_node.right is not None:
            final_node = final_node.right
        while curr_node is not final_node:
            yield curr_node.data
            if curr_node.right is not None:
                curr_node = curr_node.right
                parent_node = curr_node.parent
                while curr_node.left is not None:
                    curr_node = curr_node.left
                    parent_node = curr_node.parent
            elif parent_node is not None:
                if curr_node == parent_node.right:
                    while curr_node == parent_node.right:
                        curr_node = parent_node
                        parent_node = curr_node.parent
                curr_node = parent_node
                parent_node = curr_node.parent
        yield final_node.data
        
    def __iter__(self):
        for node in self.postorder():
            yield node.data

#node5 = LinkedBinaryTree.Node(5)
#node1 = LinkedBinaryTree.Node(1)
#node9 = LinkedBinaryTree.Node(9,node5,node1)
#node2 = LinkedBinaryTree.Node(2,node9)
#node8 = LinkedBinaryTree.Node(8)
#node4 = LinkedBinaryTree.Node(4)
#node7 = LinkedBinaryTree.Node(7,node8,node4)
#node3 = LinkedBinaryTree.Node(3,node2,node7)
#lbt = LinkedBinaryTree(node3)
#for val in lbt.iterative_inorder():
#	print(val)
