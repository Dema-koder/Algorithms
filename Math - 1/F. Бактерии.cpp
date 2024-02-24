#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define forn(i, n) for (int (i) = 0;(i) < (n); (i)++)
#define pb push_back
#define re return
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); // ifstream cin(".in");
    cout.tie(nullptr); // ofstream cout(".out");
 
    int n;
    ll m;
    cin >> n >> m;
    int a[n];
    forn(i, n)cin >> a[i];
 
    ll sum = 0;
    forn(i, n)sum += a[i];
 
    if (sum == m) {
        cout << "Yes";
        return 0;
    }
 
    bool b[(int) 1e6 + 1];
    b[0] = b[1] = false;
    forn(i, (int) 1e6 + 1)b[i] = i >= 2;
    forn(i, (int) 1e6 + 1)if (b[i])
            for (int j = i * 2; j < (int) 1e6 + 1; j += i)
                b[j] = false;
 
    forn(i, n) {
        if (b[a[i]] && (m - sum) % a[i] == 0 && (m - sum) / a[i] >= 1) {
            cout << "Yes " << i + 1 << " " << (m - sum) / a[i] + 1 << endl;
            return 0;
        }
    }
 
 
    cout << "No" << endl;
 
    return 0;
}
