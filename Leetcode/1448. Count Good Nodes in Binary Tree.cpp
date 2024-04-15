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
    int f(TreeNode* cur, int mx = -1e5) {
        if (!cur)
            return 0;
        if (cur->val >= mx)
            return 1 + f(cur->left, cur->val) + f(cur->right, cur->val);
        return f(cur->left, mx) + f(cur->right, mx);
    }

    int goodNodes(TreeNode* root) {
        return f(root);
    }
};
