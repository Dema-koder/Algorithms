class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
        unordered_map<char, int>mp;
        int i = 0, j = 0, ans = 0;
        while (j <= s.size() - 1) {
            mp[s[j++]]++;
            if (mp[s[j - 1]] == 2) 
                while (i < j && mp[s[j - 1]] == 2)
                    mp[s[i++]]--;
            else 
                ans = max(ans, j - i);
        }
        return ans;
    }
};
