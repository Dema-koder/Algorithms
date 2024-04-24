class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mn = 0, sum = 0, res = -1e9;
        for (auto to: nums) 
            sum += to, res = max(res, sum - mn), mn = min(mn, sum);
        return res;
    }
};
