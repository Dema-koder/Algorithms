n = int(input())
a = [[] for _ in range(100001)]
 
x = [int(tmp) for tmp in input().split()]
 
for i in range(n):
    a[x[i]].append(i + 1)
 
ans = []
 
for i in range(1, 100001):
    k = 0
    for j in range(i * 2, 100001, i):
        k += len(a[j])
    if k == 1:
        for j in a[i]:
            ans.append(j)
 
ans = sorted(ans)
 
print(len(ans))
 
for tmp in ans:
    print(tmp, end=' ')
