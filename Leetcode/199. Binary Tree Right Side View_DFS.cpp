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
    vector<int>ans;

    void f(TreeNode* cur, int k = 0) {
        if (!cur)
            return;
        if (k >= ans.size())
            ans.resize(k + 1);
        ans[k] = cur->val;
        f(cur->left, k + 1);
        f(cur->right, k + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        f(root);
        return ans;
    }
};
