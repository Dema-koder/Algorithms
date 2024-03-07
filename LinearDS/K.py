from collections import *
q1 = deque()
q2 = deque()
n = int(input())
for i in range(n):
    a = input().split()
    if a[0] == '+':
        q2.append(int(a[1]))       
    elif a[0] == '*':
        if len(q1) <= len(q2):
            q1.append(int(a[1]))
        else:
            q2.appendleft(int(a[1]))
    else:
        print(q1.popleft())
    if len(q1) < len(q2):
        q1.append(q2.popleft())          
