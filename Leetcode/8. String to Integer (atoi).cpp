class Solution {
public:
    int myAtoi(string s) {
        s += " ";
        int i = 0;
        while (s[i] == ' ' || s[i] == '-' || s[i] == '+') {
            if (i < s.size()) {
                if (s[i] == '-' || s[i] == '+') {
                    i++;
                    break;
                }
            } else 
                return 0;
            i++;
        }
        if (s[i] < '0' || s[i] > '9')
            return 0;
        bool b = false;
        if (i > 0)
            if (s[i - 1] == '-')
                b = true;
        long long n = 0;
        while ('0' <= s[i] && s[i] <= '9') {
            n = n * 10 + s[i] - '0';
            if (n > INT_MAX)
                return (b ? INT_MIN : INT_MAX);
            i++;
        }
        return (b ? -n : n);
    }
};
