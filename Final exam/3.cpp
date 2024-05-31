#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<char>st;
    for (int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    string t = "";
    for (auto to: st)
        t += to;
    unordered_map<char, char>mp;
    int l = 0, r = (int)t.size() - 1;
    while (l <= r) {
        mp[t[l]] = t[r];
        mp[t[r]] = t[l];
        l++; r--;
    }
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        ans += mp[s[i]];
    }
    cout << ans << endl;
}

int main(){
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
