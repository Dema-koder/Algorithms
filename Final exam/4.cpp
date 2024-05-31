#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int res = 0, cur = 1;
    for (int i = 1; i < n; i++)
        if (a[i] > a[i - 1] * 2) {
            res = max(res, cur);
            cur = 1;
        } else {
            cur++;
        }
    res = max(cur, res);
    cout << res;
}
