/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int dfs(TreeNode v, TreeNode par) {
        if (v == null)
            return 0;
        int moves = dfs(v.left, v) + dfs(v.right, v);
        int from = v.val - 1;
        par.val += from;
        moves += Math.abs(from);
        return moves;
    }

    public int distributeCoins(TreeNode root) {
        return dfs(root, new TreeNode());
    }
}
