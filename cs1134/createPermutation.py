import random

def create_permutation(n):
    output = [0]
    while len(output) < n:
        output.append(0)
    x = 0
    while x < n:
        index = random.randint(0,n-1)
        while output[index] != 0:
            index = random.randint(0,n-1)
        output[index] = x
        x += 1
    return output

#print create_permutation(6)
#print create_permutation(6)
#print create_permutation(6)
#print create_permutation(6)
#print create_permutation(6)
#print create_permutation(8)
#print create_permutation(8)
#print create_permutation(8)
#print create_permutation(8)
#print create_permutation(8)

def scramble_word(word):
    wordList = list(word)
    order = create_permutation(len(word))
    output = ""
    n = 0;
    while n < len(word):
        output += wordList[order[n]]
        n+=1
    return output

#print (scramble_word("tandon"))
#print (scramble_word("tandon"))
#print (scramble_word("tandon"))
#print (scramble_word("tandon"))

def main():
    f = open('words.txt', 'r')
    r = f.read()
    lst = r.split('\n')
    word = lst[random.randint(0,len(lst) - 1)]
    scrambled = scramble_word(word)
    scrambled = list(scrambled)
    output = ""
    for c in scrambled:
        output += c
        output += " "
    
    print("unscramble the word:" + output)
    if word == input("Try 1: "):
        print("hells yeah")
    else:
        print("Wrong!")
        if word == input("Try 2: "):
            print("hells yeah")
        else:
            print("Wrong!")
            if word == input("Try 3: "):
                print("hells yeah")
            else:
                print("Wrong! The answer was " + word + "!")
              

main()
