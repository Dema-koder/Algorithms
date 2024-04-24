class Solution {
public:
    bool canJump(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            if (res >= i)
                res = max(res, i + nums[i]);
            else 
                break;
        if (res < nums.size() - 1)
            return false;
        return true;
    }
};
