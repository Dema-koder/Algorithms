class Solution {
public:
    vector<vector<int>>ans;

    void f(vector<int>&a, vector<int>&b, int target, int ind) {
        if (0 > target)
            return;
        if (0 == target) {
            ans.push_back(b);
            return;
        }
        for (int i = ind; i < a.size(); i++) {
            b.push_back(a[i]);
            f(a, b, target - a[i], i);
            b.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>b;
        f(candidates, b, target, 0);
        return ans;
    }
};
