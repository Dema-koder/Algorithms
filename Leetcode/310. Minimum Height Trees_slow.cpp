// Находил диаметр и вершины посередине диаметра

class Solution {
public:
    int ind = -1, mx = 0;
    vector<int>ans;

    void dfs(int v, int k, vector<bool>&used, vector<vector<int>>&g) {
        used[v] = true;
        if (k > mx)
            mx = k, ind = v;
        for (auto to: g[v])
            if (!used[to])
                dfs(to, k + 1, used, g);
    }

    bool dfs2(int v, int k, vector<bool>&used, vector<vector<int>>&g) {
        if (k == mx) {
            if (k == mx / 2 || (mx % 2 == 1 && k == mx / 2 + 1))
                ans.push_back(v);
            return true;
        }
        used[v] = true;
        bool b = false;
        for (auto to: g[v])
            if (!used[to]) 
                b |= dfs2(to, k + 1, used, g);
        if (b)
            if (k == mx / 2 || (mx % 2 == 1 && k == mx / 2 + 1))
                ans.push_back(v);
        return b;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return vector<int>(1, 0);
        vector<bool>used(n, false);
        vector<vector<int>>g(n);
        for (auto to: edges) {
            g[to[0]].push_back(to[1]);
            g[to[1]].push_back(to[0]);
        }
        dfs(0, 0, used, g);
        int from = ind;
        mx = 0, ind = -1;
        fill(used.begin(), used.end(), false);
        dfs(from, 0, used, g);
        fill(used.begin(), used.end(), false);
        dfs2(from, 0, used, g);
        cout << from << " " << mx << endl;
        return ans;
    }
};
