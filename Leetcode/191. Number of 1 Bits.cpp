class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        for (int i = 0; i <= 31; i++)
            ans += ((1 << i) & n ? 1 : 0);
        return ans;
        //return __builtin_popcount(n);
    }
};
