class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() * matrix[0].size() - 1;
        int n = matrix.size(), m = matrix[0].size();
        while (l < r) {
            int mid = (r + l) / 2;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        if (matrix[r / m][r % m] == target)
            return true;
        return false;
    }
};
