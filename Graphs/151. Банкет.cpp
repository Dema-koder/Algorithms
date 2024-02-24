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
 
bool b;
vector<vector<ll>>g;
vector<ll>used;
 
void dfs(ll v, ll k) {
    used[v] = k;
    for(auto to: g[v]) 
        if (used[to] == -1)
            dfs(to, (k + 1) % 2);
        else
            if (used[to] == k) {
                b = false;
                return;
            }
}
 
int main() {
    b = true;
    ll n, m; cin >> n >> m;
    g.resize(n);
    used.resize(n, -1);
    for (int i = 0; i < m; i++) {
        ll l, r; cin >> l >> r;
        g[--l].push_back(--r);
        g[r].push_back(l);
    }
    for (int i = 0; i < n; i++) 
        if (used[i] == -1) 
            dfs(i, 0);
    if (!b) 
        cout << "NO";
    else
        cout << "YES";
}
