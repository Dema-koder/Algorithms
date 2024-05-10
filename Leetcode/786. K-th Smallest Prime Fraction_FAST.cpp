class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        int n = a.size();
        double l = 0.0, r = 1.0;

        while (l < r) {
            double m = (l + r) / 2;
            int k1 = 0;
            int p = 0, q = 1;

            for (int i = 0, j = 1; i < n - 1; i++) {
                while (j < n && a[i] > m * a[j])
                    j++;
                if (j == n)
                    break;
                k1 += n - j;
                if (p * a[j] < q * a[i]) 
                    p = a[i], q = a[j];
            }

            if (k1 == k) 
                return {p, q};
            else 
                if (k1 < k)
                    l = m;
                else 
                    r = m;
        }
        return {};
    }
};
