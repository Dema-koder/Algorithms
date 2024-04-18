class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int>dp(nums.size(), 0);
        dp[0] = nums[0], dp[1] = nums[1];
        for (int i = 2; i < nums.size(); i++) {
            for (int j = 0; j < i - 1; j++)
                dp[i] = max(dp[i], dp[j]);
            dp[i] += nums[i];
        }
        return *max_element(dp.begin(), dp.end());
    }
};
