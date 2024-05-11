class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double, int>>a(n);
        for (int i = 0; i < n; i++)
            a[i] = {(double)wage[i] / (double)quality[i], quality[i]};
        sort(a.begin(), a.end());
        priority_queue<int>pq;
        int sum = 0;
        double ans = 1e9;
        for (int i = 0; i < n; i++) {
            pq.push(a[i].second);
            sum += a[i].second;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, sum * a[i].first);
            }
        }
        return ans;
    }
};
