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
    int n = 0, ans = 0, k;

    void f(TreeNode* cur) {
        if (!cur->left && !cur->right) {
            if (++n == k)
                ans = cur->val;
            return;
        }
        if (cur->left) f(cur->left);
        if (++n == k)
            ans = cur->val;
        if (cur->right) f(cur->right);
    }

    int kthSmallest(TreeNode* root, int _k) {
        k = _k;
        f(root);
        return ans;
    }
};
