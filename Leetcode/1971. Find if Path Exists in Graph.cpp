class Solution {
public:
    vector<int>parent, rank;
    int find_set (int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set (parent[v]);
    }

    void union_sets (int a, int b) {
        a = find_set (a);
        b = find_set (b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap (a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        for (auto to: edges)
            union_sets(to[0], to[1]);
        int s1 = find_set(source), s2 = find_set(destination);
        return s1 == s2;
    }
};
