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
    TreeNode* f(int& ind, vector<int>&pre, vector<int>&in, int l, int r) {
        if (l > r)
            return nullptr;
        int v = pre[ind];
        TreeNode* cur = new TreeNode(v);

        for (int i = l; i <= r; i++)
            if (in[i] == v) {
                ind++;
                cur->left = f(ind, pre, in, l, i - 1);
                cur->right = f(ind, pre, in, i + 1, r);
                break;
            }
        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ind = 0;
        return f(ind, preorder, inorder, 0, inorder.size() - 1);
    }
};
