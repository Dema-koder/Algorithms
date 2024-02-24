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
 
ll k;
vector<vector<ll>>g;
vector<bool>used;
 
void dfs(ll v) {
    used[v] = true;
    for (auto to : g[v])
        if (!used[to]) 
            dfs(to);
}
 
int main() {
    ll n; cin >> n;
    g.resize(n);
    used.resize(n, false);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            ll x; cin >> x;
            if (x == 1) {
                k++;
                g[i].push_back(j);
            }
        }
    dfs(0);
    bool b = true;
    for (int i = 0; i < n; i++)
        if (used[i] == false)
            b = false;
    if (k / 2 == n - 1 && b)
        cout << "YES";
    else
        cout << "NO";
}
