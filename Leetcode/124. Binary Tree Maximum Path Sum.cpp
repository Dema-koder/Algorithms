/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, pair<int, int>>dp;
    int ans = -1e8;

    int dfs(TreeNode* v) {
        if (!v) return 0;
        if (!v->left && !v->right) {
            dp[v] = {v->val, v->val};
            ans = max(ans, dp[v].second);
            return dp[v].second;
        }
        int s1 = dfs(v->left);
        int s2 = dfs(v->right);
        dp[v].first = max(v->val, max(s1 + v->val, max(s2 + v->val, s1 + s2 + v->val)));
        dp[v].second = max(v->val, max(s1 + v->val, s2 + v->val));
        ans = max(ans, dp[v].first);
        return dp[v].second;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
