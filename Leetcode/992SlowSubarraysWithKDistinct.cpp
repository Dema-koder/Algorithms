#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <unordered_set>
#include <stack>
#include <set>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int>arr;

class Solution {
private:
	unordered_set<int>t[80000];
	vector<int>a;

	void build(int v, int vl, int vr) {
		if (vl == vr) {
			t[v].insert(a[vl]);
			return;
		}
		int vm = (vl + vr) / 2;
		build(2 * v + 1, vl, vm);
		build(2 * v + 2, vm + 1, vr);
		for (auto to : t[2 * v + 1])
			t[v].insert(to);
		for (auto to : t[2 * v + 2])
			t[v].insert(to);
	}

	unordered_set<int> query(int v, int vl, int vr, int l, int r) {
		if (vr < l || vl > r) {
			unordered_set<int>s;
			return s;
		}
		if (l <= vl && vr <= r)
			return t[v];
		int vm = (vl + vr) / 2;
		unordered_set<int>s1 = query(2 * v + 1, vl, vm, l, r);
		unordered_set<int>s2 = query(2 * v + 2, vm + 1, vr, l, r);
		unordered_set<int>ans;
		for (auto to : s1)
			ans.insert(to);
		for (auto to : s2)
			ans.insert(to);
		return ans;
	}

	int bin(int k, int ind) {
		int l = 0, r = ind;
		while (l < r - 1) {
			int m = (l + r) / 2;
			if (query(0, 0, a.size() - 1, m, ind).size() > k)
				l = m;
			else
				r = m;
		}
		if (query(0, 0, a.size() - 1, l, ind).size() == k)
			return l;
		return r;
	}

public:
	Solution() {}

	int subarraysWithKDistinct(vector<int>& nums, int k) {
		for (auto to : nums)
			a.push_back(to);
		int ans = 0;
		build(0, 0, nums.size() - 1);
		for (int i = k - 1; i < nums.size(); i++) {
			if (query(0, 0, a.size() - 1, 0, i).size() < k)
				continue;
			int l = bin(k, i), r = bin(k - 1, i);
			if (k == 1)
				ans += i - l + 1;
			else 
				ans += r - l;
		}
		return ans;
	}
};

Solution sol;

int main() {
	int n, k1; cin >> n >> k1;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << sol.subarraysWithKDistinct(arr, k1);
}
