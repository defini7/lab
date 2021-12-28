# Usage: python3 todo_manager.py <filename> <comment sign>

import sys

try:
    filename = sys.argv[1]
except FileNotFoundError:
    assert(False, 'please provide file')

try:
    f = open(filename, 'r')
except IOError:
    assert(False, 'could not open the file')

sym = ''

try:
    sym = sys.argv[2]
except Exception:
    assert(False, 'please specify comment')

write_in_file = False

try:
    out = open(sys.argv[2], 'w')
except Exception:
    write_in_file = False

for s in f.readlines():
    if s.find(sym) > -1:
        com = s.find('TODO')
        if write_in_file:
            out.write('\n')
        if com > -1:
            while s[com].isspace():
                com += 1
            while s[com] != '\n':
                print(s[com], end='')
                if write_in_file:
                    out.write(s[com])
                com += 1
            print('\n')
        else:
            continue
    else:
        continue

f.close()

if write_in_file:
    out.close()
