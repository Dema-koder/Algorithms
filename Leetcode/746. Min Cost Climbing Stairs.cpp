class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pp = cost[0], p = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int cur = min(pp, p) + cost[i];
            pp = p, p = cur;
        }
        return min(p, pp);
    }
};
