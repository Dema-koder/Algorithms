n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
 
sum = 0
for i in a:
    sum += i
 
if sum == m:
    print("Yes")
else:
    b = [True for i in range(int(1e6) + 1)]
    for i in range(int(1e6) + 1):
        b[i] = i >= 2
    for i in range(int(1e6) + 1):
        if b[i]:
            j = i * 2
            while j < int(1e6) + 1:
                b[j] = False
                j += i
    for i in range(n):
        if b[a[i]] and (m - sum) % a[i] == 0 and (m - sum) / a[i] >= 1:
            print("Yes", i + 1, (m - sum) // a[i] + 1)
            break
    else:
        print("No")
