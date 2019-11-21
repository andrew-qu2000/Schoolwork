def get_tag(text):
    tag = ''
    flag = False
    for char in text:
        if char == "<":
            flag = True
        if flag:
            tag += char
        if char == ">":
            flag = False
            yield tag
            tag = ''

#txt = "<head>nottag</head><title><dog></dog></title><marquee></marquee>edge"
#for tag in get_tag(txt):
 #   print(tag)

def is_matched_html(expr):
    tag_list = []
    for tag in get_tag(expr):
        if not tag[1] == "/":
            tag_list.append(tag)
        else:
            prev_tag = tag_list[len(tag_list) - 1]
            prev_name = prev_tag[1:len(prev_tag) - 1]
            curr_name = tag[2:len(tag) - 1]
            if(prev_name == curr_name):
                tag_list.pop()
            else:
                print(tag_list)
                return False
    return len(tag_list) == 0
    
#print(is_matched_html(txt))

with open("sampleHTML.txt","r") as text:
    content = text.read()
    #for tag in get_tag(content):
     #   print(tag)
    print(is_matched_html(content))
