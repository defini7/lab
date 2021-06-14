def duplicate_encode(word):
    return "".join(["(" if word.lower().count(x) == 1 else ")" for x in word.lower()])
