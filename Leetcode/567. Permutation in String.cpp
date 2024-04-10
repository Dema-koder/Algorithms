class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int>mp_s1, mp;
        for (int i = 0; i < s1.size(); i++)
            mp_s1[s1[i]]++;
        int i = 0, j = 0, kol = 0;
        while (true) {
            if (j - i < s1.size()) {
                if (j == s2.size())
                    break;
                if (mp_s1.find(s2[j]) != mp_s1.end()) {
                    if (mp[s2[j]] < mp_s1[s2[j]])
                        kol++;
                    mp[s2[j]]++;
                }
                j++;
            } else 
                if (j - i == s1.size()) {
                    if (kol == s1.size()) {
                        //cout << i << " " << j << endl;
                        return true;
                    }
                    if (j == s2.size())
                        break;
                    
                    if (mp_s1.find(s2[i]) != mp_s1.end()) {
                        if (mp[s2[i]] <= mp_s1[s2[i]])
                            kol--;
                        mp[s2[i]]--;
                    }
                    if (mp_s1.find(s2[j]) != mp_s1.end()) {
                        if (mp[s2[j]] < mp_s1[s2[j]])
                            kol++;
                        mp[s2[j]]++;
                    }
                    i++, j++;
                }
        }
        return false;
    }
};
