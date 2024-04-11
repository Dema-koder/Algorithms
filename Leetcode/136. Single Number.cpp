class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto to: nums)
            ans ^= to;
        return ans;
    }
};
