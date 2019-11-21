def appearances(s,low,high):
    if(low == high):
        return {s[low]:1}
    d = appearances(s,low + 1,high)
    if s[low] in d:
        d[s[low]] += 1
    else:
        d[s[low]] = 1
    return d
