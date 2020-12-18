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
    public boolean isValidBST(TreeNode root) {
        return BST(root, Long.MAX_VALUE, Long.MIN_VALUE);
    }
    private boolean BST(TreeNode root, long max_v, long min_v){
        if(root == null){
            return true;
        }
        if(root.val <= min_v || root.val >= max_v){
            return false;
        }
        return BST(root.left, root.val, min_v) && BST(root.right, max_v, root.val);
    }
}