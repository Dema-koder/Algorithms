#include <iostream>
#include <vector>

using namespace std;

//ifstream cin("input.txt");
//ofstream cout("output.txt");

int const INF = 1000000000;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>>a(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	vector<vector<int>>dp(n, vector<int>(m, INF));
	dp[0][0] = a[0][0];
	for (int i = 1; i < m; i++)
		dp[0][i] = dp[0][i - 1] + a[0][i];
	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + a[i][0];

	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];

	cout << dp[n - 1][m - 1] << endl;

	vector<char>ans;
	int i = n - 1, j = m - 1;
	while (i != 0 || j != 0) {
		if (i == 0) {
			ans.push_back('R');
			j--;
		} else
		if (j == 0) {
			ans.push_back('D');
			i--;
		} else 
		if (dp[i - 1][j] > dp[i][j - 1]) {
			ans.push_back('D');
			i--;
		}
		else {
			ans.push_back('R');
			j--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i];
}
