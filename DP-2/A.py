n = int(input())
dp = [n + 1] * (n + 1)

dp[1] = 1
for i in range(1, n):
    dp[i + 1] = min(dp[i + 1], dp[i] + 1)
    if 2 * i <= n:
        dp[2 * i] = min(dp[2 * i], dp[i] + 1)
    if 3 * i <= n:
        dp[3 * i] = min(dp[3 * i], dp[i] + 1)

answer = []
res = n
while res > 1:
    answer.append(res)
    if dp[res - 1] + 1 == dp[res]:
        res = res - 1
    elif res % 2 == 0 and dp[res // 2] + 1 == dp[res]:
        res = res // 2
    elif res % 3 == 0 and dp[res // 3] + 1 == dp[res]:
        res = res // 3
answer.append(1)

print(dp[n] - 1)
print(' '.join(map(str, reversed(answer))))

