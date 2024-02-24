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
vector<bool>used;
 
void dfs(ll v) {
    used[v] = true;
    for (auto to: g[v])
        if (!used[to])
            dfs(to);
}
 
int main() {
    ll n, s; cin >> n >> s;
    g.resize(n);
    used.resize(n, false);
    while (true) {
        ll l, r; cin >> l;
        if (l == 0) 
            break;
        cin >> r;
        g[--l].push_back(--r);
    }
    dfs(s - 1);
    ll ans = 0;
    for (auto to: used)
        if (to == false) {
            cout << "No";
            exit(0);
        }
    cout << "Yes";
}
