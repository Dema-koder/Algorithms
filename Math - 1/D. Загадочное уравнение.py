n = int(input())

s = 0
while (s + 1) * (s + 1) <= n + 1:
	s += 1

ans = 0
for i in range(s):
	if (n + 1) % (i + 1) == 0:
		ans += 1
		if (i + 1) * (i + 1) != n + 1:
			ans += 1

print(ans)
