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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        st.push(root);
        root = root->left;
        while (!st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (--k == 0)
                return st.top()->val;
            root = st.top();
            st.pop();
            root = root->right;
            if (root) {
                st.push(root);
                root = root->left;
            }
        }
        return 0;
    }
};
