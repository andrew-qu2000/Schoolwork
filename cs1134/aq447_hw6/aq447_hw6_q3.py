import DoublyLinkedList

class CompactString:

    def __init__(self,orig_str):
        self.data = DoublyLinkedList.DoublyLinkedList()
        if orig_str == '':
            return
        else:
            curr_char = orig_str[0]
            count = 0
            for char in orig_str:
                if char == curr_char:
                    count += 1
                else:
                    self.data.add_last( (curr_char,count) )
                    curr_char = char
                    count = 1
        self.data.add_last( (curr_char,count) )

    def __add__(self,other):
        new_str = ''
        for tup in self.data:
            for i in range(tup[1]):
                new_str += tup[0]
        for tup in other.data:
            for i in range(tup[1]):
                new_str += tup[0]
        return CompactString(new_str)

    def __lt__(self,other):
        if len(self.data) == 0:
            return len(other.data) > 0
        elif len(other.data) == 0:
            return False
        else:
            char_self = ''
            char_other = ''
            parser_self = self.data.first_node()
            parser_other = other.data.first_node()
            count_self = 1
            count_other = 1
            while char_self == char_other:
                print(char_self + ":" + char_other)
                if count_self > parser_self.data[1]:
                    parser_self = parser_self.next
                    count_self = 1
                if count_other > parser_other.data[1]:
                    parser_other = parser_other.next
                    count_other = 1
                if parser_self == self.data.trailer:
                    return parser_other != other.data.trailer
                else:
                    char_self = parser_self.data[0]
                    char_other = parser_other.data[0]
                    count_self += 1
                    count_other += 1
            return char_self < char_other

    def __le__(self,other):
        if len(self.data) == 0:
            return True
        elif len(other.data) == 0:
            return False
        else:
            if len(self.data) != len(other.data):
                return self < other
            parser_self = self.data.first_node()
            parser_other= other.data.first_node()
            for i in range(len(self.data) - 1):
                if parser_self.data != parser_other.data:
                    return self < other
                parser_self = parser_self.next
                parser_other = parser_other.next
            return True

    def __gt__(self,other):
        return not(self <= other)

    def __ge__(self,other):
        return not(self < other)
        
    def __repr__(self):
        ret = ''
        for tup in self.data:
            for i in range(tup[1]):
                ret += tup[0]
        return ret
