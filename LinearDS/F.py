import sys
sys.stdin = open('input.txt', 'rt')
sys.stdout = open('output.txt', 'wt')
first = list(map(int, input().split()))
second = list(map(int, input().split()))
n = 0
fl = True
while first and second:

    n += 1
    a, b = first.pop(0), second.pop(0)
    if (a > b and not (b == 0 and a == 9)) or (a == 0 and b == 9):
        first.append(a)
        first.append(b)
    else:
        second.append(a)
        second.append(b)
    if n >= 1000000:
        print('botva')
        fl = False
        break
if fl:
    print('first' if first else 'second', n)
