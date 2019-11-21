def can_construct(ransom_note,magazine):
    ransom_note = list(ransom_note)
    magazine = list(magazine)
    for c in ransom_note:
        count = 0
        for ch in ransom_note:
            if c == ch:
                count += 1
        count2 = 0
        for cha in magazine:
            if c == cha:
                count2 += 1
        if count > count2:
            return False
    return True

print(can_construct("aaa","abaa"))
