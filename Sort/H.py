n = int(input())
arr = []
for i in range(n):
    s, t = (int(i) for i in input().split())
    arr.append((i + 1, s, t))
arr = sorted(arr, key=lambda x: (-x[1], x[2], x[0]))
print(*[i[0] for i in arr])
