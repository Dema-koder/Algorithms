#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, x1, y1, x2, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
	x1--, y1--, x2--, y2--;
	vector<vector<int>>g(n * n);
	vector<pair<int, int>>moves({ {1, 2}, {-1, 2}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {-2, 1}, {-2, -1} });
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (auto to : moves) {
				int x = i + to.first, y = j + to.second;
				if (x >= 0 && x < n && y >= 0 && y < n)
					g[i * n + j].push_back(x * n + y);
			}
	queue<int>q;
	vector<bool>used(n * n, false);
	vector<int>d(n * n, 1e9);
	q.push(x1 * n + y1);
	d[x1 * n + y1] = 0;
	while (!q.empty()) {
		int v = q.front();
		used[v] = true;
		q.pop();
		for (auto to : g[v])
			if (!used[to])
				d[to] = d[v] + 1,
				used[to] = true,
				q.push(to);
	}
	cout << d[x2 * n + y2];
}
