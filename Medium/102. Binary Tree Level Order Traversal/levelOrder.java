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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        doLevelOrder(root, 0, ans);
        return ans;    
    }
    private void doLevelOrder(TreeNode root, int depth, List<List<Integer>> ans){
        if(root == null){
            return;
        }
        while(ans.size() <= depth){
            ans.add(new ArrayList<Integer>());
        }
        ans.get(depth).add(root.val);
        doLevelOrder(root.left, depth+1, ans);
        doLevelOrder(root.right, depth+1, ans);
    }
}