#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    deque <pair <int, int>> q;
    vector <int> ans(n);
    for (int i = 0; i < n; i ++) {
        while (!q.empty() && q.back().first > a[i]) {
            ans[q.back().second] = i;
            q.pop_back();
        }
        q.push_back({a[i], i});
    }
    if (q.empty()) {
        for (auto i : ans) {
            cout << i << " ";
        }
    }
    else {
        for (auto i : q) {
            ans[i.second] = -1;
        }
        for (auto i : ans) {
            cout << i << " ";
        }
    }
    return 0;
}
