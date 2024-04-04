from sys import stdin, stdout
 
 
def main():
    n, k = map(int, stdin.readline().split())
    l = map(int, stdin.readline())
    frog = [False] * (n + 1)
    for i in list(map(int, stdin.readline().split())):
        frog[i] = True
 
    dp = [0] * (n + 1)
 
    dp[1] = 1
 
    for i in range(2, n + 1):
        if not frog[i]:
            for j in range(max(1, i - k), i):
                dp[i] += dp[j]
 
    stdout.write(str(dp[n]))
 
 
# 1. dp[i] - кол-во способов добраться до i-го столбика
# 2. dp[1] = 1
#    dp[2] = dp[1] = 1
#    dp[3] = dp[2] + dp[1]
# 3. dp[i] = sum(dp[i-k..i-1])
# 4. возр. i
# 5. dp[n]
 
 
main()
