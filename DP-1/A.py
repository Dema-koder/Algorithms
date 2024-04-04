from sys import stdin, stdout
 
 
def main():
    n, k = map(int, stdin.readline().split())
    dp = [0] * (n + 1)
    pref = [0] * (n + 1)
 
    dp[1] = 1
    pref[1] = dp[1]
 
    for i in range(2, n + 1):
        if i - 1 > k:
            dp[i] = pref[i - 1] - pref[i - k - 1]
        else:
            dp[i] = pref[i - 1]
        pref[i] = dp[i] + pref[i - 1]
 
    stdout.write(str(dp[n]))
 
 
main()
