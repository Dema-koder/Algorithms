class Solution {
public:
    int kk = 0;
    void dfs(int v, vector<int>&kol, vector<bool>&used, vector<int>&d, vector<vector<int>>&g, int k) {
        used[v] = true;
        kk++;
        d[0] += k;
        int x = kk;
        for (auto to: g[v])
            if (!used[to])
                dfs(to, kol, used, d, g, k + 1);
        kol[v] = kk - x + 1;
    }

    void dfs2(int v, int par, vector<bool>&used, vector<vector<int>>&g, vector<int>&d, vector<int>&kol) {
        used[v] = true;
        if (v != 0) 
            d[v] = d[par] - 2 * kol[v] + g.size(); 
        for (auto to: g[v])
            if (!used[to])
                dfs2(to, v, used, g, d, kol);
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>kol(n, 0);
        vector<bool>used(n, false);
        vector<vector<int>>g(n);
        vector<int>d(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0, kol, used, d, g, 0);
        fill(used.begin(), used.end(), false);
        dfs2(0, -1, used, g, d, kol);
        return d;
    }
};
