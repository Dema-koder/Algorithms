class Solution {
public:
    vector<int>mp;

    int longestIdealString(string s, int k) {
        mp.resize(26, 0);
        if (s == "") 
            return 0;
        mp[s[0] - 'a'] = 1;
        int ans = 1;
        for (int i = 1; i < s.size(); i++) {
            mp[s[i] - 'a']++;
            for (int j = max(0, s[i] - 'a' - k); j <= min(25, s[i] - 'a' + k); j++)
                if (j != s[i] - 'a')
                    mp[s[i] - 'a'] = max(mp[s[i] - 'a'], mp[j] + 1);
            ans = max(ans, mp[s[i] - 'a']);
        }
        return ans;
    }
};
