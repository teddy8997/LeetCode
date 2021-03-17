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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if(root == null){
            return root;
        }
        if(d == 1){
            TreeNode n = new TreeNode(v);
            n.left = root;
            return n;
        }
        if(d == 2){
            TreeNode l = root.left;
            root.left = new TreeNode(v);
            root.left.left = l;
            TreeNode r = root.right;
            root.right = new TreeNode(v);
            root.right.right = r;
        }else{
            addOneRow(root.left, v, d-1);
            addOneRow(root.right, v, d-1);
        }
        return root;
    }
}