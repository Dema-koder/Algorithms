class Solution {
private:
    string dig = "";
    map<int, vector<char>>mp;
public:
    void f(string dig, int ind, vector<string>&ans, string prev = "") {
        if (ind == dig.size()) {
            if (prev.size() > 0)
                ans.push_back(prev);
            return;
        }
        for (auto to: mp[dig[ind] - '0']) 
            f(dig, ind + 1, ans, prev + to);
    }

    vector<string> letterCombinations(string digits) {
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        dig = digits;
        vector<string>ans;
        f(digits, 0, ans);
        return ans;
    }
};
