class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans = 0, ans1 = 0;
        for (int i = happiness.size() - 1; i >= 0; i--) {
            int x = happiness.size() - 1 - i, x1 = k - i;
            if (happiness.size() - 1 - i < k)
                ans += (happiness[i] - x > 0 ? happiness[i] - x : 0);
            if (i < k)
                ans1 += (happiness[i] - x1 > 0 ? happiness[i] - x1 : 0);
        }
        return max(ans, ans1);
    }
};
