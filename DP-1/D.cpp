#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x.begin(), x.end());

    vector<ll> c(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    for (int i = m - 1; i >= 1; i--)
        c[i] = min(c[i], c[i + 1]);

    vector<ll> dp(n);
    dp[0] = c[1];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + c[1];
        for (int j = 0; j <= i; j++) {
            dp[i] = min(dp[i],
                        c[x[i] - x[j] + 1] + (j > 0 ? dp[j - 1] : 0));
        }
    }

    cout << dp[n - 1];

}
