class Solution {
public:
    vector<vector<int>>ans;

    void f(vector<int>&b, vector<int>&a) {
        if (b.size() == a.size())
            ans.push_back(b);
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 100) {
                b.push_back(a[i]);
                a[i] = 100;
                f(b, a);
                a[i] = b.back();
                b.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>b;
        f(b, nums);
        return ans;
    }
};
