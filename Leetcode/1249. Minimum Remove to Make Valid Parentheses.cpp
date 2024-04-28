class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<int>idx;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(')
                st.push(i);
            else 
                if (s[i] == ')')
                    if (st.empty())
                        idx.push_back(i);
                    else 
                        st.pop();
        while (!st.empty()) {
            idx.push_back(st.top());
            st.pop();
        }
        sort(idx.begin(), idx.end());
        string ans = "";
        int k = 0;
        for (int i = 0; i < s.size(); i++)
            if (k < idx.size() && idx[k] == i) {
                k++;
                continue;
            }
            else {
                ans += s[i];
            }
        return ans;
    }
};
