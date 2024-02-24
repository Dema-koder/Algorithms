#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cmath>
#include <deque>
#include <random>
#include <string>
#include <stack>
 
using namespace std;
              
typedef long long ll;
 
ll n, m;
vector<vector<bool>>g;
vector<vector<bool>>used;
 
void dfs(ll i, ll j) {
    used[i][j] = true;
    if (j < m - 1)
        if (!used[i][j + 1] && g[i][j + 1])
            dfs(i, j + 1);
    if (i < n - 1) 
        if (!used[i + 1][j] && g[i + 1][j])
            dfs(i + 1, j);
    if (i > 0) 
        if (!used[i - 1][j] && g[i - 1][j])
            dfs(i - 1, j);
    if (j > 0) 
        if (!used[i][j - 1] && g[i][j - 1])
            dfs(i, j - 1);
}
 
int main() {
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++)
        used[i].resize(m, false);
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#')
                g[i].push_back(true);
            else
                g[i].push_back(false);
        }
    ll k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (g[i][j] && !used[i][j]) {
                dfs(i, j);
                k++;
            }
    cout << k;
}
