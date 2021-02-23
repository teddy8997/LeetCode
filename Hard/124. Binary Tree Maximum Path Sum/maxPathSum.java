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
    int ans = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        if(root == null){
            return 0;
        }
        maxPath(root);
        return ans;
    }
    private int maxPath(TreeNode root){
        if(root == null){
            return 0;
        }
        int l = Math.max(0, maxPath(root.left));
        int r = Math.max(0, maxPath(root.right));
        int sum = l + r + root.val;
        ans = Math.max(ans, sum);
        return Math.max(l, r) + root.val;
    }
}