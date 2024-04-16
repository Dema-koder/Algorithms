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
    void f(TreeNode* cur, int val, int depth, int k = 0) {
        if (!cur)
            return;
        if (k == depth - 1) {
            auto newleft = new TreeNode(val);
            newleft->left = cur->left;
            auto newright = new TreeNode(val);
            newright->right = cur->right;
            cur->left = newleft;
            cur->right = newright;
            return;
        }
        f(cur->left, val, depth, k + 1);
        f(cur->right, val, depth, k + 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dummy = new TreeNode();
        dummy->left = root;
        f(dummy, val, depth);
        return dummy->left;
    }
};
