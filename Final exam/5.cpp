#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

vector<vector<int>>g;
vector<bool>used;
vector<double>ans;

void dfs(int v, int p) {
	used[v] = true;
	int k = 0;
	for (auto to : g[v])
		if (!used[to]) 
			dfs(to, v), k++;
	if (k != 0) {
		for (int i = 0; i < g[v].size(); i++)
			if (g[v][i] != p)
				ans[v] += ans[g[v][i]];
		ans[v] /= (p != -1 ? (g[v].size() - 1) : g[v].size());
		ans[v]++;
	}
}

int main() {
	int n; cin >> n;
	g.resize(n);
	ans.resize(n, 0);
	used.resize(n, false);
	for (int i = 0; i < n - 1; i++) {
		int l, r; cin >> l >> r;
		g[--l].push_back(--r);
		g[r].push_back(l);
	}
	dfs(0, -1);
	cout << fixed << setprecision(10) << ans[0];
}
