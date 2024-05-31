#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <unordered_set>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector<ll>pref(n, a[0]);
		for (int i = 1; i < n; i++)
			pref[i] = pref[i - 1] + (i % 2 == 1 ? -a[i] : a[i]);

		set<ll>st;
		st.insert(pref[0]);
		bool b = false;
		for (int i = 1; i < n; i++) {
			if (st.find(pref[i]) != st.end() || pref[i] == 0)
				b = true;
			st.insert(pref[i]);
		}
		cout << (b ? "yes\n" : "no\n");
	}
}
