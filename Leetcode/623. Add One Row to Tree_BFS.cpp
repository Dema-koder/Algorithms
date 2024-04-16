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

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* dummy = new TreeNode();
        dummy->left = root;
        queue<pair<int, TreeNode*>>q;
        q.push({0, dummy});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (!cur.second)
                continue;

            if (cur.first == depth - 1) {
                auto newleft = new TreeNode(val);
                newleft->left = cur.second->left;
                auto newright = new TreeNode(val);
                newright->right = cur.second->right;
                cur.second->left = newleft;
                cur.second->right = newright;
            } else {
                q.push({cur.first + 1, cur.second->left});
                q.push({cur.first + 1, cur.second->right});
            }
        }
        return dummy->left;
    }
};
