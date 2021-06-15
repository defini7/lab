def anagrams(word, words):
    is_match = sorted(word)
    return [w for w in words if is_match == sorted(w)]
