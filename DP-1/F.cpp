#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> pref(n);
    ll ans = LONG_LONG_MIN;
    ll minPref = 0;

    for (int i = 0; i < n; i++) {
        cin >> pref[i];
        pref[i] += (i > 0 ? pref[i - 1] : 0);

        if (i >= k - 1) {
            ans = max(ans, pref[i] - minPref);
            minPref = min(minPref, pref[i - k + 1]);
        }
    }

    cout << ans;

}
