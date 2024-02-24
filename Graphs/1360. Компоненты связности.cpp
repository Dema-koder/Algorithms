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
 
vector<vector<ll>>g;
vector<ll>used;
 
void dfs(ll v, ll k) {
    used[v] = k;
    for (auto to: g[v])
        if (used[to] == 0) 
            dfs(to, k);
}
 
int main() {
    ll n, m; cin >> n >> m;
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; i++) {
        ll l, r; cin >> l >> r;
        g[--l].push_back(--r);
        g[r].push_back(l);
    }
    ll k = 1;
    for (int i = 0; i < n; i++) 
        if (used[i] == 0) {
            dfs(i, k);
            k++;
        }
    cout << k - 1 << endl;
    vector<vector<ll>>ans(k - 1);   
    for (int i = 0; i < n; i++) 
        ans[used[i] - 1].push_back(i + 1);
    for (int i = 0; i < k - 1; i++) {
        cout << ans[i].size() << endl;
        for (auto to: ans[i])
            cout << to << " ";
        cout << endl;
    }
}
