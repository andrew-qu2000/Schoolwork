import DoublyLinkedList
            
def insert_sorted(srt_lnk_lst,elem):
    parser = srt_lnk_lst.header.next
    while (parser != srt_lnk_lst.trailer and parser.data < elem):
        parser = parser.next
    prev_holder = parser.prev
    parser.prev = DoublyLinkedList.DoublyLinkedList.Node(elem,prev_holder,parser)
    prev_holder.next = parser.prev
    
ll = DoublyLinkedList.DoublyLinkedList()
ll.add_last(3)
ll.add_last(6)
ll.add_last(7)
ll.add_last(10)
insert_sorted(ll,6)
insert_sorted(ll,7)
