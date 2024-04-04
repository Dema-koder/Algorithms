#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 1 2 3 4 5 6 7 8 9 10
    // [       ]
    //     [ ]
    //           [   ]
    //         [ ]
    //                   [
    //                   ]
    // *     * *   *   *
    // 1 1 2 1 1 1 1 0 0 0

    pair<int, int> p[n * 2 + m];
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        p[i * 2] = {min(a, b), -1};
        p[i * 2 + 1] = {max(a, b), m};
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[n * 2 + i].first;
        p[n * 2 + i].second = i;
    }
    sort(p, p + n * 2 + m);

    int cnt = 0;
    int ans[m];
    for (int i = 0; i < n * 2 + m; ++i) {
        if (p[i].second == -1)
            cnt++;
        else if (p[i].second == m)
            cnt--;
        else
            ans[p[i].second] = cnt;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << ' ';
    }


    return 0;
}
