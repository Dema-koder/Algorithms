class Solution {
public:
    int ans = 0;
    vector<pair<int, int>>moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int x, int y, vector<vector<int>>&grid, vector<vector<bool>>&used) {
        used[x][y] = true;
        for (auto to: moves) {
            int x_new = x + to.first, y_new = y + to.second;
            if (x_new >= 0 && x_new < grid.size() && y_new >= 0 && y_new < grid[0].size()) {
                if (!used[x_new][y_new]) {
                    if (grid[x_new][y_new])
                        dfs(x_new, y_new, grid, used);
                    else 
                        ans++;
                }
            } else 
                ans++;
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>>used(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j]) {
                    dfs(i, j, grid, used);
                    return ans;
                }
        return 0;
    }
};
