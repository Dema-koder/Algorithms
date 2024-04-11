class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == k)
            return "0";
        if (k == 0)
            return num;
        stack<char>st;
        
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0) {
                char cur = st.top();
                if (cur > num[i]) {
                    st.pop();
                    k--;
                } else 
                    break;
            }
            st.push(num[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        num = "";
        while (!st.empty()) {
            num += st.top();
            st.pop();
        }
        reverse(num.begin(), num.end());
        while (num[0] == '0')
            num.erase(0, 1);
        if (num == "")
            return "0";
        return num;
    }
};
