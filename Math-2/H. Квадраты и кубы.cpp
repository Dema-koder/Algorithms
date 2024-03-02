#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll msqrt(ll x) {
    ll y = sqrt(x);
    while (y*y > x)
        --y;
    while ((y+1)*(y+1) <= x)
        ++y;
    return y;
}
 
int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0;
    for (ll y = 1; y*y*y <= b; ++y) {
        ll yyy = y*y*y;
        if (yyy < a)
            continue;
        ans += max(0LL, msqrt(min(b, yyy+k)) - (msqrt(max(a, yyy-k)-1)+1) + 1);
    }
    cout << ans << "\n";
}
