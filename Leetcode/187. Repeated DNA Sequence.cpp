class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int>mp;
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (t.size() < 10)
                t += s[i];
            if (t.size() == 10) {
                mp[t]++;
                t.erase(0, 1);
            }
        }
        vector<string>ans;
        for (auto to: mp)
            if (to.second > 1)
                ans.push_back(to.first);
        return ans;
    }
};
