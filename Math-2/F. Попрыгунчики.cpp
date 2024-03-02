#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    cin >> n;
    vector <ll> hi(n);
    for (int i = 0; i < n; i ++) {
        cin >> hi[i];
    }
    ll p = hi[0];
    for (int i = 0; i < n; i ++) {
        p = p / gcd(hi[i], p) * hi[i];
    }
    int f = 1;
    for (int i = 0; i < n; i ++) {
        ll x = p / hi[i];
        if (x % 2 == 0) {
            f = 0;
            break;
        }
    }
    if (f) {
        cout << p;
    }
    else {
        cout << -1;
    }
    return 0;
}
