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
    bool f(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot)
            return root == subRoot;
        return root->val == subRoot->val && f(root->left, subRoot->left) && f(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root || !subRoot)
            return root == subRoot;
        if (root->val == subRoot->val)
            if (f(root, subRoot))
                return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
