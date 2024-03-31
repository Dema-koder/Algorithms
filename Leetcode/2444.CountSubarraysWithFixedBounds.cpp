/*
minInd - последний на данный момент индекс минимального числа(minK)
maxInd - послдений на данный сосент индекс максимального числа(maxK)
kolLess - количество чисел меньших minK на отрезке [l, i]
kolMore - количество чисел больших maxK на отрезке [l, i]

В случае если на отрезке [l, i] есть числа меньшие minK или большие maxK то двигаем переменную l
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int minInd = -1, maxInd = -1, l = 0, kolLess = 0, kolMore = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == minK)
                minInd = i;
            if (nums[i] == maxK)
                maxInd = i;
            if (nums[i] < minK)
                kolLess++;
            if (nums[i] > maxK) 
                kolMore++;
            while (kolMore > 0 || kolLess > 0) {
                if (nums[l] > maxK)
                    kolMore--;
                if (nums[l] < minK)
                    kolLess--;
                l++;
                if (l == i)
                    break;
            } 
            if (minInd >= l && maxInd >= l) {
                ans += abs(l - min(minInd, maxInd)) + 1;
            }
        }
        return ans;
    }
};
