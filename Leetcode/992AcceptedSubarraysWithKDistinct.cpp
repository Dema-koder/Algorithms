#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<int>arr;

class Solution {
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		unordered_map<int, int>mp;
		for (int i = 0; i < k; i++)
			mp[nums[i]] = i;
		int l = 0, r = k - 1, ans = 0;
		while (true) {
			if (mp.size() < k) {
				if (r == nums.size() - 1)
					break;
				r++, mp[nums[r]] = r;
			}
			else
				if (mp.size() > k) {
					if (mp[nums[l]] == l)
						mp.erase(nums[l]);
					l++;
				}
				else {
					int res = 1e5;
					for (auto to : mp) {
						if (to.first != nums[r])
							res = min(res, to.second);
					}
					if (res == 1e5)
						ans += abs(l - mp[nums[r]]) + 1;
					else
						ans += (res - l + 1);
					if (r == nums.size() - 1)
						break;
					r++;
					mp[nums[r]] = r;
				}
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
