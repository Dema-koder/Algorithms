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
    int h = 0;
    int f(TreeNode* v) {
        if (!v) 
            return 0;
        int s1 = f(v->left);
        int s2 = f(v->right);
        h = max(h, abs(s1 - s2));
        return max(s1, s2) + 1;
    }

    bool isBalanced(TreeNode* root) {
        f(root);
        return (h > 1 ? false : true);
    }
};
