#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

vector<vector<ll>>g;
vector<bool>used;

int main() {
    int n; cin >> n;
    used.resize(n, false);
    g.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x == 1)
                g[i].push_back(j);
        }
    int s, t; cin >> s >> t;
    s--, t--;
    queue<int>q;
    vector<int>d(n, 1e9);
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        used[v] = true;
        q.pop();
        for (auto to : g[v])
            if (!used[to])
                used[to] = true,
                d[to] = d[v] + 1,
                q.push(to);
    }
    if (d[t] == 1e9)
        cout << -1;
    else
        cout << d[t];
}
