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
    string f(TreeNode* cur) {
        if (!cur->left && !cur->right) {
            string s; s += char(cur->val + 'a');
            return s;
        }
        if (!cur->left)
            return f(cur->right) + char(cur->val + 'a');
        if (!cur->right)
            return f(cur->left) + char(cur->val + 'a');
        string s1 = f(cur->left) + char(cur->val + 'a'), s2 = f(cur->right) + char(cur->val + 'a');
        if (s1.size() < s2.size())
            swap(s1, s2);
        if (s1.substr(0, s2.size()) == s2 && s1[s2.size()] < s1[s2.size() - 1])
            return s1;
        return min(s1, s2);
    }

    string smallestFromLeaf(TreeNode* root) {
        return f(root);
    }
};
