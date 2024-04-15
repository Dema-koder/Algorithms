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
    vector<vector<int>>ans;

    void f(TreeNode* cur, int k) {
        if (!cur)
            return;
        if (ans.size() <= k)
            ans.resize(k + 1);
        ans[k].push_back(cur->val);
        f(cur->left, k + 1);
        f(cur->right, k + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        f(root, 0);
        return ans;
    }
};
