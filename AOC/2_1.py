hor = 0
dep = 0

with open('input2.txt', 'r') as f:
    for l in f:
        l = l.split()
        if l[0] == 'forward':
            hor += int(l[1])
        elif l[0] == 'up':
            dep -= int(l[1])
        elif l[0] == 'down':
            dep += int(l[1])

print(hor * dep)
