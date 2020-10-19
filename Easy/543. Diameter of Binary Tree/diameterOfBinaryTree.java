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
    private int ans_;
    public int diameterOfBinaryTree(TreeNode root) {
        ans_ = 0;
        DoT(root);
        return ans_;
    }
    private int DoT(TreeNode root){
        if(root == null){
            return -1;
        }
        int l = DoT(root.left) + 1;
        int r = DoT(root.right) + 1;
        ans_ = Math.max(ans_, l + r);
        return Math.max(l, r);
    }
}