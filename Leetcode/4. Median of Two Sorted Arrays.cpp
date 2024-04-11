class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int l = 0, r = nums1.size(), k = (nums1.size() + nums2.size() + 1) / 2;
        while (l <= r) {
            int m = (l + r) / 2;
            int ind = k - m;

            double l1 = (m > 0 ? nums1[m - 1] : -1e7), r1 = (m < nums1.size() ? nums1[m] : 1e7);
            double l2 = (ind > 0 ? nums2[ind - 1] : -1e7), r2 = (ind < nums2.size() ? nums2[ind] : 1e7);
            
            if (l1 <= r2 && l2 <= r1) {
                if ((nums1.size() + nums2.size()) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                return max(l1, l2);
            }
            else 
                if (l1 > r2) 
                    r = m - 1;
                else 
                    l = m + 1;
        }
        return 0;
    }
};
