class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead;
        for (auto to: deadends)
            dead.insert(to);
        if (dead.find("0000") != dead.end())
            return -1;
        if (target == "0000")
            return 0;
        unordered_map<char, pair<char, char>>mp;
        mp['0'] = {'9', '1'};
        mp['1'] = {'0', '2'};
        mp['2'] = {'1', '3'};
        mp['3'] = {'2', '4'};
        mp['4'] = {'3', '5'};
        mp['5'] = {'4', '6'};
        mp['6'] = {'5', '7'};
        mp['7'] = {'6', '8'};
        mp['8'] = {'7', '9'};
        mp['9'] = {'8', '0'};

        unordered_map<string, int> d;
        queue<string>q;
        q.push("0000");
        d["0000"] = 0;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            string tmp = cur;
            for (int i = 0; i < cur.size(); i++) {
                tmp[i] = mp[cur[i]].first;
                if (tmp == target) return d[cur] + 1;
                if (d.find(tmp) == d.end() && dead.find(tmp) == dead.end()) {
                    q.push(tmp);
                    d[tmp] = d[cur] + 1;
                }
                tmp[i] = mp[cur[i]].second;
                if (tmp == target) return d[cur] + 1;
                if (d.find(tmp) == d.end() && dead.find(tmp) == dead.end()) {
                    q.push(tmp);
                    d[tmp] = d[cur] + 1;
                }
                tmp = cur;
            }
        }
        return -1;
    }
};
