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
    int dist(TreeNode* v) {
        if (!v)
            return 0;
        int s1 = dist(v->left);
        int s2 = dist(v->right);
        ans = max(ans, s1 + s2);
        return max(s1, s2) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dist(root);
        return ans;
    }
};
