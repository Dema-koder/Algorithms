#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


void solve(){
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> arr(n + m + 1);
    for(auto &i : arr) cin >> i.first;
    for(auto &i : arr) cin >> i.second;
    int fst_p = -1;
    int fst_t = -1;
    int cnt_p = 0, cnt_t = 0;
    ll ans = 0;
    for(int i = 0; i < n + m; i += 1){
        if(arr[i].first > arr[i].second){
            if(cnt_p < n){
                cnt_p += 1;
                ans += arr[i].first;
            }else{
                if(fst_p == -1){
                    fst_p = i;
                }
                cnt_t += 1;
                ans += arr[i].second;
            }
        }else{
            if(cnt_t < m){
                cnt_t += 1;
                ans += arr[i].second;
            }else{
                if(fst_t == -1){
                    fst_t = i;
                }
                cnt_p += 1;
                ans += arr[i].first;
            }
        }
    }
    // cout << fst_p << ' ' << fst_t << ' ' << ans << '\n';
    for(int i = 0; i < n + m + 1; i += 1){
        ll tmp = ans;
        if(arr[i].first > arr[i].second){
            if(fst_p > i){
                tmp -= arr[i].first;
                tmp += arr[fst_p].first;
                tmp -= arr[fst_p].second;
                tmp += arr[n + m].second;
            }else if(fst_p <= i && fst_p != -1){
                tmp -= arr[i].second;
                tmp += arr[n+m].second;
            }else if(fst_p == -1){
                tmp -= arr[i].first;
                tmp += arr[n + m].first;
            }
        }else{
            if(fst_t > i){
                tmp -= arr[i].second;
                tmp += arr[fst_t].second;
                tmp -= arr[fst_t].first;
                tmp += arr[n + m].first;
            }else if(fst_t <= i && fst_t != -1){
                tmp -= arr[i].first;
                tmp += arr[n + m].first;
            }else if(fst_t == -1){
                tmp -= arr[i].second;
                tmp += arr[n + m].second;
            }
        }
        cout << tmp << ' ';
    }
    cout << '\n';
}



signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
