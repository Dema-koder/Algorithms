def SmartSolve(n, q, arr):
	pref = [0] * (n+1)
	for i in range(1, n+1):
		pref[i] = pref[i-1] + arr[i-1]

	l = 0
	r = n
	while l + 1 < r:
		m = (l + r) // 2

		sm = 0
		for i in range(n-m+1):
			sm = max(sm, pref[i+m] - pref[i])

		if sm <= q:
			l = m
		else:
			r = m
	if pref[-1] <= q:
		return -1
	return r

n, q = map(int, input().split())
a = list(map(int, input().split()))

print(SmartSolve(n, q, a))
