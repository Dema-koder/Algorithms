class Solution {
public:
    vector<int>a;
    vector<vector<int>>ans;

    void f(vector<int>b, int ind) {
        if (ind == a.size()) {
            ans.push_back(b);
            return;
        }
        f(b, ind + 1);
        b.push_back(a[ind]);
        f(b, ind + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        a = nums;
        f({}, 0);
        return ans;
    }
};
