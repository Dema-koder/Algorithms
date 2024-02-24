num = input().split()
a = int(num[0])
b = int(num[1])
prime = [True] * (b + 1)
prime[0], prime[1] = False, False
for i in range(2, b + 1, 1):
    if prime[i]:
        j = 2
        while i * j <= b:
            prime[i * j] = False
            j += 1
ans = []
for i in range(a, b + 1):
    if prime[i]:
        ans.append(i)
ans = [str(t) for t in ans]
print(' '.join(ans))
