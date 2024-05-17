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
    public boolean f(TreeNode cur, int target) {
        if (cur == null)
            return true;
        if (cur.left == null && cur.right == null && cur.val == target)
            return true;
        if (cur.left == null && cur.right == null)
            return false;
        boolean l = f(cur.left, target), r = f(cur.right, target);
        if (l) cur.left = null;
        if (r) cur.right = null;
        if (l && r && cur.val == target)
            return true;
        return false;
    }

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        boolean b = f(root, target);
        if (b)
            root = null;
        return root;
    }
}
