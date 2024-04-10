class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp1, mp;
        int kol = 0;
        for (auto to: t)
            mp1[to]++;
        int i = 0, j = 0;
        string ans = s + "abc";
        while (true) {
            if (kol == t.size()) {
                while (kol == t.size()) {
                    if (mp1.find(s[i]) != mp1.end()) {
                        if (mp[s[i]] <= mp1[s[i]])
                            kol--;
                        mp[s[i]]--;
                    }
                    i++;
                }
                if (ans.size() > j - i + 1)
                    ans = s.substr(i - 1, j - i + 1);
            } else {
                if (j == s.size())
                    break;
                if (mp1.find(s[j]) != mp1.end()) {
                    if (mp[s[j]] < mp1[s[j]])
                        kol++;
                    mp[s[j]]++;
                }
                j++;
            }
        }
        if (ans == s + "abc")
            return "";
        return ans;
    }
};
