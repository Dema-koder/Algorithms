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
    int ans = 0;

    void f(TreeNode* v, int d) {
        if (v == nullptr)
            return;
        ans = max(ans, d);
        f(v->left, d + 1);
        f(v-> right, d + 1);
    }

    int maxDepth(TreeNode* root) {
        f(root, 1);
        return ans;
    }
};
