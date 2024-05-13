class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            if (grid[i][0] == 0)
                for (int j = 0; j < m; j++)
                    grid[i][j] = 1 - grid[i][j];
        for (int i = 0; i < m; i++) {
            int k = 0;
            for (int j = 0; j < n; j++)
                k += grid[j][i];
            if (k <= n / 2)
                for (int j = 0; j < n; j++)
                    grid[j][i] = 1 - grid[j][i];
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res += grid[i][j] * (1 << (m - 1 - j));
        return res;
    }
};
