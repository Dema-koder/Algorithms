#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n;
    cin >> n;
    vector<long long> ans(n + 1);
    ans[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i + 1; j++) {
            if ((i + 1) % j == 0) {
                ans[i] += ans[j - 1];
                if (j > 1 && (i + 1) / j != j)
                    ans[i] += ans[(i + 1) / j - 1];
            }
        }
    }
    cout << ans[n] << '\n';
 
    return 0;
}
