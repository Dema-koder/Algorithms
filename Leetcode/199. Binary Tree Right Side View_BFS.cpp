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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        unordered_map<TreeNode*, int>mp;
        if (root != nullptr) {
            q.push(root);
            mp[root] = 0;
        } else
            return ans;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (q.empty() || mp[q.front()] != mp[cur])
                ans.push_back(cur->val);
            if (cur->left!=NULL) {
                q.push(cur->left);
                mp[cur->left] = mp[cur] + 1;
            }
            if (cur->right!=NULL) {
                q.push(cur->right);
                mp[cur->right] = mp[cur] + 1;
            }
        }
        return ans;
    }
};
