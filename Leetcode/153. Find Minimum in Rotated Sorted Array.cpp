class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];
        int first = nums[0], last = nums[nums.size() - 1];
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (r + l) / 2;
            if (nums[m] >= first) 
                l = m + 1;
            else 
                r = m;
        }
        return nums[r];
    }
};
