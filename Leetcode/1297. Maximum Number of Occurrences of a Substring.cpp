class Solution {
public:
    int solve(string& s, int k, int cur) {
        string t = "";
        unordered_map<char, int>mp;
        unordered_map<string, int>ans;
        int l = 0;
        for (int i = 0; i <= s.size(); i++) 
            if (t.size() < cur)
                t += s[i], mp[s[i]]++;
            else 
                if (t.size() == cur) {
                    if (mp.size() <= k)
                        ans[t]++;
                    if (mp[s[l]] == 1)
                        mp.erase(s[l]);
                    else 
                        mp[s[l]]--;
                    l++;
                    t.erase(0, 1);
                    t += s[i], mp[s[i]]++;
                }
        int mx = 0;
        for (auto to: ans)
            mx = max(mx, to.second);
        return mx;
    }

    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int mx = solve(s, maxLetters, minSize);
        return mx;
    }
};
