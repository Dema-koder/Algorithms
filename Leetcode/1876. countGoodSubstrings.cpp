class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s == "")
            return 0;
        vector<int>a(26, 0);
        int i = 0, j = -1, k = 0, ans = 0;
        while (true) {
            if (j - i + 1 < 3) {
                j++;
                if (j == s.size())
                    break;
                if (a[s[j] - 'a'] == 0)
                    k++;
                a[s[j] - 'a']++;
            } else {
                if (j - i + 1 == 3) {
                    if (k == 3) 
                        ans++;
                    if (a[s[i] - 'a'] == 1)
                        k--;
                    a[s[i] - 'a']--;
                    i++;
                    j++;
                    if (j == s.size())
                        break;
                    if (a[s[j] - 'a'] == 0)
                        k++;
                    a[s[j] - 'a']++;
                }
            }
        }
        return ans;
    }
};
