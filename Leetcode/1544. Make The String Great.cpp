class Solution {
public:
    string makeGood(string s) {
        if (s.size() == 0) return s;
        stack<char>st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (abs(st.top() - s[i]) == abs('a' - 'A'))
                st.pop();
            else 
                st.push(s[i]);
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
