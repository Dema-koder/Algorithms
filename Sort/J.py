n = int(input())
arr = []
for i in range(n):
    arr.append(tuple(int(i) for i in input().split()))
arr = sorted(arr, key=lambda x: x[1])
k = 1
lst = arr[0][1]
for i in range(1, n):
    if arr[i][0] >= lst:
        lst = arr[i][1]
        k += 1
print(k)
