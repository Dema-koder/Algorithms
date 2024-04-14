class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i] % n;
            nums[cur] += n;
            if (nums[cur] / n >= 2)
                return cur;
        }
        return 0;
    }
};
