#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int x, y; cin >> x >> y;
    int res = 0;
    while (true) {
        if (y >= 2)
            res++, y-=2, x -= 7;
        else
            if (y == 1)
                res++, y = 0, x -= 11;
            else
                if (x > 0) {
                    res += (x + 14) / 15;
                    break;
                } else {
                    break;
                }
    }
    cout << res << endl;
}

int main(){
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
