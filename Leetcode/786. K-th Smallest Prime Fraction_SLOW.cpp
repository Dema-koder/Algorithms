class Solution {
public:

    struct frac{
        int a, b, i1, i2;

        bool operator<(const frac& f) const {
            int dem = b * f.b / __gcd(b, f.b);
            return a * (dem / b) > f.a * (dem / f.b);
        }
    };

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<frac>pq;
        for (int i = 1; i < arr.size(); i++)
            pq.push({1, arr[i], 0, i});
        while (!pq.empty()) {
            k--;
            auto cur = pq.top();
            if (k == 0)
                return {cur.a, cur.b};
            pq.pop();

            if (cur.i1 + 1 < cur.i2) 
                pq.push({arr[cur.i1 + 1], cur.b, cur.i1 + 1, cur.i2});
        }
        return {};
    }
};
