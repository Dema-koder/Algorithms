#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int dp[n][m];
    dp[0][0] = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }        
            int val = 1e9;
            if (i != 0) {
                val = min(val, dp[i - 1][j]);
            }
            if (j != 0) {
                val = min(val, dp[i][j - 1]);
            }
            dp[i][j] = a[i][j] + val;
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}
