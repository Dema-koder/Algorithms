#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<vector<ll>>g;
vector<bool>used;

void dfs(ll v) {
    used[v] = true;
    for (auto to : g[v])
        if (!used[to])
            dfs(to);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    used.resize(n, false);
    g.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x == 1)
                g[i].push_back(j);
        }
    dfs(k - 1);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (used[i])
            ans++;
    cout << ans - 1;
}
