class Solution {
public:
    vector<vector<bool>>can;
    vector<vector<int>>dp;

    int specialPerm(vector<int>& nums) {
        dp.resize(14, vector<int>(1 << 14, -1));
        can.resize(nums.size(), vector<bool>(nums.size(), false));
        for (int i = 0; i < nums.size(); i++) 
            for (int j = 0; j < nums.size(); j++)
                can[i][j] = nums[i] % nums[j] == 0;
        return solve(nums.size(), 0, 0);
    }

    int solve(int n, int i, int mask) {
        if (mask == (1 << n) - 1) return 1;
        if (dp[i][mask] != -1) return dp[i][mask];

        long long res = 0;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) != 0) continue;
            if (mask == 0 || can[i][j] || can[j][i])
                res += solve(n, j, mask|(1<<j));
        }
        return dp[i][mask] = res % (long long)(1e9 + 7);
    }
};
