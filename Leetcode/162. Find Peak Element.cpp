class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        if (nums.size() == 2) 
            return (nums[0] > nums[1] ? 0 : 1);
        if (nums[0] > nums[1])
            return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        int l = 0, r = nums.size() - 1;
        while (r - l > 1) {
            int m = (r + l) / 2;
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
                return m;
            else 
                if (nums[m] < nums[m + 1] && nums[m + 1] >= nums[m - 1])
                    l = m + 1;
                else 
                    if (nums[m] < nums[m - 1] && nums[m - 1] >= nums[m + 1])
                        r = m - 1;
        }
        return (nums[l] > nums[r] ? l : r);
    }
};
