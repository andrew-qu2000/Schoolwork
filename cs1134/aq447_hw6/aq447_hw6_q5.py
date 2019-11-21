import DoublyLinkedList

def merge_linked_lists(srt_lnk_lst1,srt_lnk_lst2):
    def merge_sublists(node1,node2):
        ret = DoublyLinkedList.DoublyLinkedList()
        if node1.next is None:
            while node2.next is not None:
                ret.add_last(node2.data)
                node2 = node2.next
        elif node2.next is None:
            while node1.next is not None:
                ret.add_last(node1.data)
                node1 = node1.next
        else:
            if node1.data <= node2.data:
                ret = merge_sublists(node1.next,node2)
                ret.add_first(node1.data)
            else:
                ret = merge_sublists(node1,node2.next)
                ret.add_first(node2.data)
        return ret
    return merge_sublists(srt_lnk_lst1.first_node(),srt_lnk_lst2.first_node())


