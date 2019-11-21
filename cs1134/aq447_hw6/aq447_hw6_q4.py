import DoublyLinkedList

def copy_linked_list(lnk_lst):
    ret = DoublyLinkedList.DoublyLinkedList()
    for elem in lnk_lst:
        ret.add_last(elem)
    return ret

def deep_copy_linked_list(lnk_lst):
    ret = DoublyLinkedList.DoublyLinkedList()
    cursor = lnk_lst.first_node()
    while cursor != lnk_lst.trailer:
        if type(cursor.data) == int:
            ret.add_last(cursor.data)
        else:
            ret.add_last(deep_copy_linked_list(cursor.data))
        cursor = cursor.next
    return ret
