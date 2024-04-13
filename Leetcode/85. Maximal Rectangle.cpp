class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>arr(matrix[0].size());
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) 
                if (i == 0)
                    arr[j] = matrix[i][j] - '0';
                else 
                    if (matrix[i][j] == '1')
                        arr[j]++;
                    else 
                        arr[j] = 0;
            ans = max(ans, largestRectangleArea(arr));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        vector<int>left(heights.size()), right(heights.size());
        for (int i = 0; i < heights.size(); i++) 
            if (i == 0) {
                left[i] = 0;
                st.push(0);
            }
            else {
                while (heights[st.top()] >= heights[i]) {
                    st.pop();
                    if (st.empty()) {
                        left[i] = 0;
                        break;
                    }
                }
                if (!st.empty())
                    left[i] = st.top() + 1;
                st.push(i);
            }
        while (!st.empty())
            st.pop();

        for (int i = heights.size() - 1; i >= 0; i--) {
            if (i == heights.size() - 1) 
                right[i] = heights.size() - 1;
            else {
                while (heights[st.top()] >= heights[i]) {
                    st.pop();
                    if (st.empty()) {
                        right[i] = heights.size() - 1;
                        break;
                    }
                }
                if (!st.empty())
                    right[i] = st.top() - 1;
            }
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};
