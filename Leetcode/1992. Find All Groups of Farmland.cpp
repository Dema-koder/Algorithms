class Solution {
public:
    vector<pair<int, int>>moves{{1, 0}, {0, 1}};

    void dfs(int i, int j, vector<vector<int>>&ans, vector<vector<int>>&land) {
        land[i][j] = 0;
        ans[ans.size() - 1][2] = max(ans[ans.size() - 1][2], i);
        ans[ans.size() - 1][3] = max(ans[ans.size() - 1][3], j);
        for (auto to: moves) {
            int x = i + to.first, y = j + to.second;
            if (x >= 0 && x < land.size() && y >= 0 && y < land[0].size())
                if (land[x][y] == 1)
                    dfs(x, y, ans, land);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        for (int i = 0; i < land.size(); i++) 
            for (int j = 0; j < land[i].size(); j++)
                if (land[i][j] == 1) {
                    ans.resize(ans.size() + 1);
                    ans[ans.size() - 1].resize(4);
                    ans[ans.size() - 1][0] = i, ans[ans.size() - 1][1] = j;
                    dfs(i, j, ans, land);
                }
        return ans;
    }
};
