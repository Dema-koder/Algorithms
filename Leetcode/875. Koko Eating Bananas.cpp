class Solution {
public:
    long long ok(vector<int>&piles, long long k) {
        long long ans = 0;
        for (auto to: piles)
            ans += (to % k == 0 ? to / k : to / k + 1);
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 1e18;
        while (l < r) {
            long long m = (r + l) / 2;
            if (ok(piles, m) > h)
                l = m + 1;
            else 
                r = m;
        }
        return r;
    }
};
