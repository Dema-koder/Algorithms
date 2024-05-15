class Solution {
public:
    int n;

    void f(int x, int y, int m, vector<vector<bool>>&used, vector<vector<int>>&d, vector<pair<int, int>>&moves) {
        used[x][y] = true;
        for (auto to: moves) {
            int x1 = x + to.first, y1 = y + to.second;
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n)
                if (!used[x1][y1] && d[x1][y1] >= m)
                    f(x1, y1, m, used, d, moves);
        }
    }

    void bfs(vector<vector<int>>&d, vector<pair<int, int>>&moves, vector<vector<int>>&grid) {
        queue<pair<int, int>>q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    q.push({i, j});
                    d[i][j] = 0;
                }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto to: moves) {
                int x1 = cur.first + to.first, y1 = cur.second + to.second;
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n)
                    if (d[x1][y1] > d[cur.first][cur.second] + 1) {
                        q.push({x1, y1});
                        d[x1][y1] = d[cur.first][cur.second] + 1;
                    }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>>d(n, vector<int>(n, 1e9));
        vector<pair<int, int>>moves{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        bfs(d, moves, grid);

        vector<vector<bool>>used(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>>pq;

        pq.push({d[0][0], {0, 0}});
        used[0][0] = true;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int res = cur.first;
            int x = cur.second.first, y = cur.second.second;

            if (x == n - 1 && y == n - 1)
                return res;
            
            for (auto to: moves) {
                int x1 = x + to.first, y1 = y + to.second;
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n)
                    if (grid[x1][y1] != 1 && !used[x1][y1]) {
                        used[x1][y1] = true;
                        pq.push({min(res, d[x1][y1]), {x1, y1}});
                    }
            }
        }
        return 0;
    }
};
