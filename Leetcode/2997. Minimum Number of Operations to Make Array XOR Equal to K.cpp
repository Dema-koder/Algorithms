class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
            res ^= nums[i];
        int ans = 0;
        while (k || res) {
            if (k % 2 != res % 2)
                ans++;
            k /= 2, res /= 2;
        }
        return ans;
    }
};
