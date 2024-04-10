class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end()); // сортировка подсчетом дольше почему то
        
        queue<int>q;
        for (int i = 0; i < deck.size(); i++)
            q.push(i);
        vector<int>a;
        while (!q.empty()) {
            a.push_back(q.front());
            q.pop();
            if (q.empty())
                break;
            int x = q.front();
            q.pop();
            q.push(x);
        }
        
        vector<int>ans(deck.size());
        int k = 0;
        for (int i = 0; i < a.size(); i++)
            ans[a[i]] = deck[k++];
        return ans;
    }
};
