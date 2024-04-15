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
    int f(TreeNode* cur, int n, int k) {
        if (!cur)
            return 0;
        if (!cur->left && !cur->right)
            return cur->val + 10 * n;
        int m = n * 10 + cur->val;
        return f(cur->left, m, k + 1) + f(cur->right, m, k + 1); 
    }

    int sumNumbers(TreeNode* root) {
        return f(root, 0, 0);
    }
};
