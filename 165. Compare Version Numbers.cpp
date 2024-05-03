class Solution {
public:
    string f(string& str) {
        string ans = "";
        int i = 0;
        while (str[i] == '0')
            i++;
        while (i < str.size())
            ans += str[i], i++;
        return ans;
    }

    int compareVersion(string version1, string version2) {
        string t = "", s = "";
        int i = 0, j = 0;
        while (true) {
            while (i < version1.size() && version1[i] != '.')
                t += version1[i], i++;
            while (j < version2.size() && version2[j] != '.')
                s += version2[j], j++;
            t = f(t), s = f(s);
            int x = (t == "" ? 0 : stoi(t)), y = (s == "" ? 0 :stoi(s));
            if (x < y)
                return -1;
            else 
                if (x > y)
                    return 1;
            if (i >= version1.size() && j >= version2.size())
                break;
            s = "", t = "";
            i++, j++;
        }
        return 0;
    }
};
