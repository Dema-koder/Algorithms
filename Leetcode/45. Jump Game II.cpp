// из каждой поззиции ищем куда прыгнуть будет выгоднее всего
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i + nums[i] >= nums.size() - 1)
                return ans + 1;
            int mx = 0, ind = 0;
            for (int j = i; j < nums[i] + i + 1; j++) {
                if (j == nums.size())
                    break;
                if (mx < nums[j] + j)
                    mx = nums[j] + j, ind = j;
            }
            i = ind - 1, ans++;
        }
        return ans; 
    }
};
