class Solution {
public:
    vector<vector<bool>>used;
    vector<pair<int, int>>moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<char>>&g, int x, int y) {
        used[x][y] = true;
        for (auto to: moves) {
            int x1 = x + to.first, y1 = y + to.second;
            if (x1 >= 0 && x1 < g.size() && y1 >= 0 && y1 < g[0].size())
                if (!used[x1][y1] && g[x1][y1] == '1')
                    dfs(g, x1, y1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int k = 0;
        used.resize(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (!used[i][j] && grid[i][j] == '1') {
                    k++;
                    dfs(grid, i, j);
                }
        return k;
    }
};
