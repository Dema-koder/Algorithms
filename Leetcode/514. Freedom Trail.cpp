class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>>mp;
        for (int i = 0; i < ring.size(); i++)
            mp[ring[i]].push_back(i);
        vector<vector<pair<int, int>>>dp(key.size()); // first - индекс той буквы на котором остановились, second - количество ходов
        int ans = 1e9;
        for (auto to: mp[key[0]]) {
            dp[0].push_back({to, min(to, (int)ring.size() - to)});
            if (0 == key.size() - 1)
                ans = min(ans, min(to, (int)ring.size() - to));
        }
        for (int i = 1; i < key.size(); i++) {
            for (auto to: mp[key[i]]) {
                int res = 1e9;
                for (int j = 0; j < dp[i - 1].size(); j++) {
                    res = min(res, dp[i - 1][j].second + min(abs(to - dp[i - 1][j].first), (int)ring.size() - abs(to - dp[i - 1][j].first)));
                }
                dp[i].push_back({to, res});
                if (i == key.size() - 1)
                    ans = min(ans, res);
            }
        }
        return ans + key.size();
    }
};
