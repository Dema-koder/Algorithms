class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = nums[0], last = nums[nums.size() - 1];
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] >= first) 
                l = m + 1;
            else 
                r = m;
        }
        if (target >= first)
            l = 0;
        else 
            l = r, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < target) 
                l = m + 1;
            else 
                r = m;
        }
        if (nums[r] == target)
            return r;
        return -1;
    }
};
