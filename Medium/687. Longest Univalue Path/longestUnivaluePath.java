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
    int ans = 0;
    public int longestUnivaluePath(TreeNode root) {
        if(root == null){
            return 0;
        }
        getLongest(root);
        return ans;
    }
    private int getLongest(TreeNode root){
        if(root == null){
            return 0;
        }
        int l = getLongest(root.left);
        int r = getLongest(root.right);
        int lenL = 0;
        int lenR = 0;
        if(root.left != null && root.val == root.left.val){
            lenL = 1 + l;
        }
        if(root.right != null && root.val == root.right.val){
            lenR = 1 + r;
        }
        ans = Math.max(ans, lenL + lenR);
        return Math.max(lenL, lenR);
    }
}