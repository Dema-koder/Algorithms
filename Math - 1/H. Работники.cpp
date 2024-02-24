#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <ctime>
#include <random>
#include <bitset>
 
#define ll long long
#define ld long double
#define mod (ll) 1000000007
using namespace std;
 
//ifstream cin("input.txt"); ofstream cout("output.txt");
//ifstream cin("fsa.txt"); ofstream cout("result.txt");
 
int main() {
	//ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(1e6 + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[x].push_back(i);
	}
	vector<int> ans;
	for (int i = 1; i <= 1e6; i++) {
		int k = 0;
		for (int j = 2*i; j <= 1e6; j+=i) {
			k += a[j].size();
		}
		if (k == 1) {
			for (int j = 0; j < a[i].size(); j++) {
				ans.push_back(a[i][j]);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
