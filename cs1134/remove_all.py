import DoublyLinkedList

lnk_lst = DoublyLinkedList.DoublyLinkedList()
lnk_lst.add_last(2)
lnk_lst.add_last(4)
lnk_lst.add_last(6)

def remove_all(lnk_lst,val):
    if lnk_lst.is_empty():
        return
    cursor = lnk_lst.first_node()
    while cursor is not lnk_lst.trailer:
        if cursor.data == val:
            next_node = cursor.next
            lnk_lst.delete_node(cursor)
            cursor = next_node
        else:
            cursor = cursor.next

def max_in_link_list(lnk_lst):
    
    def max_in_link_list_helper(lnk_lst,node):
        if node.next == lnk_lst.trailer:
            return node.data
        return max(node.data , max_in_link_list_helper(lnk_lst,node.next))
    
    return max_in_link_list_helper(lnk_lst,lnk_lst.first_node())
