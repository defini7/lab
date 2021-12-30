hor = 0
dep = 0
aim = 0

with open('input.txt', 'r') as f:
    for l in f:
        l = l.split()
        if l[0] == 'forward':
            hor += int(l[1])
            if aim != 0:
                dep += aim * int(l[1])
        elif l[0] == 'up':
            aim -= int(l[1])
        elif l[0] == 'down':
            aim += int(l[1])

print(hor * dep)
