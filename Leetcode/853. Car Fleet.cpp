class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<int>a(target, 0);
        for (int i = 0; i < position.size(); i++)
            a[position[i]] = speed[i];
        int k = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != 0)
                position[k] = i, speed[k] = a[i], k++;
        stack<int>st;
        int ans = 0;
        for (int i = position.size() - 1; i >= 0; i--) {
            if (st.empty())
                st.push(i); 
            else {
                int ind = st.top();
                if ((double)(target - position[ind]) / (double)speed[ind] < (double)(target - position[i]) / (double)speed[i]) {
                    ans++;
                    while (!st.empty())
                        st.pop();
                    st.push(i);
                }
            }
        }
        if (!st.empty())
            ans++;
        return ans;
    }
};
