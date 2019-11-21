import ChainingHashTableMap

class InvertedFile:

    def __init__(self, file_name):
        text = open(file_name, 'r')
        content = text.read()
        tokens_list = content.split()
        self.ht = ChainingHashTableMap.ChainingHashTableMap()
        for ind in range( len(tokens_list) ):
            word = tokens_list[ind]
            if word[-1] not in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ':
                word = word[0:-1]
            word = word.lower()
            if word in self.ht:
                lst = self.ht[word]
                lst.append(ind)
                self.ht[word] = lst
            else:
                self.ht[word] = [ind]

    def indices(self, word):
        if word in self.ht:
            return self.ht[word]
        return []
