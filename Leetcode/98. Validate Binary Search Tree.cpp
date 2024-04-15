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
    bool b = true;

    pair<int, int> f(TreeNode* cur) { 
        if (!cur->left && !cur->right)
            return {cur->val, cur->val};
        pair<int, int>ans;
        if (!cur->right) {
            auto l = f(cur->left);
            if (l.second >= cur->val) b = false;
            ans = {l.first, cur->val};
        } else
        if (!cur->left) {
            auto r = f(cur->right);
            if (r.first <= cur->val) b = false;
            ans = {cur->val, r.second};
        } else {
            auto l = f(cur->left), r = f(cur->right);
            if (l.second >= cur->val || r.first <= cur->val) b = false;
            ans = {l.first, r.second};
        }
        return ans;
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        f(root);
        return b;
    }
};
