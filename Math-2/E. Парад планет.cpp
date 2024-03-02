#include <bits/stdc++.h>
 
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd (b, a % b) : a;
}
 
int main()
{
    long long n, k, a, l, u, c = 1;
    cin >> n >> k >> a;
    for (int i = 0; i < n; i++){
        cin >> l >> u;
        c = c * (l / u) / gcd(c, l / u);
    }
    if (k - a >= c)
        cout << "Yes\n" << a + c;
    else 
        cout << "No";
}
