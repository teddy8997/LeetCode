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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        doDFS(root, 0, ans);
        return ans;
    }
    private void doDFS(TreeNode root, int d, List<Integer> ans) {
        if(root == null){
            return;
        }
        if(ans.size() <= d){
            ans.add(root.val);
        }
        doDFS(root.right, d+1, ans);
        doDFS(root.left, d+1, ans);
    }
}