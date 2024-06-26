class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, ans = 0;
        while (i <= j) {
            if (limit - people[j] < people[i])
                j--;
            else 
                j--, i++;
            ans++;
        }
        return ans;
    }
};
