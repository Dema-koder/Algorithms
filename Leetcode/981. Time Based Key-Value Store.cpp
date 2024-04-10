class TimeMap {
public:
    unordered_map<string, map<int, string>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto x = mp[key].upper_bound(timestamp);
        if (x == mp[key].begin())
            return "";
        x--;
        return x->second;
    }
};


class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = mp[key].size() - 1;
        if (r == -1) return "";
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (mp[key][m].second <= timestamp) 
                l = m;
            else 
                r = m - 1;
        }
        if (mp[key][r].second <= timestamp)
            return mp[key][r].first;
        else 
            if (mp[key][l].second <= timestamp)
                return mp[key][l].first;
        return "";
    }
};
