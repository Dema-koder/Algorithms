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
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        return query(nums, k) - query(nums, k - 1);
    }

    int query(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        unordered_map<int, int>mp;
        mp[nums[0]]++;
        int l = 0, r = 0, ans = 0;
        while (true) {
            if (mp.size() > k) {
                if (mp[nums[l]] == 1)
                    mp.erase(nums[l]);
                else
                    mp[nums[l]]--;
                l++;
            }
            else {
                ans += (r - l + 1);
                r++;
                if (r == nums.size())
                    break;
                mp[nums[r]]++;
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
