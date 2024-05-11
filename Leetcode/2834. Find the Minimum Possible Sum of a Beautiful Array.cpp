class Solution {
public:
    int minimumPossibleSum(long long n, long long target) {
        long long ans = 0;
        if (target / 2 < n) {
            long long x = (1 + target / 2) * (target / 2);
            ans += x / 2;
            x = (target + target + (n - target / 2 - 1)) * (n - target / 2);
            ans += x / 2;
        } else {
            long long x = (1 + n) * n;
            ans += x / 2;
        }
        return ans % (long long)(1e9 + 7);
    }
};
