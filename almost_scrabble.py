def high(x):
    POINTS = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6, 'g': 7, 'h': 8, 'i': 9, 'j': 10, 'k': 11, 'l': 12, 'm': 13, 'n': 14, 'o': 15, 'p': 16, 'q': 17, 'r': 18, 's': 19, 't': 20, 'u': 21, 'w': 22, 'v': 23, 'x': 24, 'y': 25, 'z': 26}
    words = x.split()
    words_grades = [0 for i in range(len(words))]
    counter = 0
    for word in words:
        for char in word:
            words_grades[counter] += POINTS[char]
        counter += 1
    return words[words_grades.index(max(words_grades))]
