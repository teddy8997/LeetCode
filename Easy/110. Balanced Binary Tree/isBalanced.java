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
    boolean ans = true;
    public boolean isBalanced(TreeNode root) {
        checkIsBalanced(root);
        return ans;
    }
    private int checkIsBalanced(TreeNode root){
        if(root == null || ans == false){
            return 0;
        }
        int leftChild = checkIsBalanced(root.left);
        int rightChild = checkIsBalanced(root.right);
        if(Math.abs(leftChild - rightChild) > 1){
            ans = false;
            return 0;
        }
        return Math.max(leftChild, rightChild) + 1;
    }
}