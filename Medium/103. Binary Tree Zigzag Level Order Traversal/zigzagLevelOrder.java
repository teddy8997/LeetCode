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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> levelNode = new ArrayList<>();
        doLevelOrder(root, 0, levelNode);
        for (int i = 1; i < levelNode.size(); i+=2) {
            Collections.reverse(levelNode.get(i));
        }
        return levelNode;
    }
    private void doLevelOrder(TreeNode root, int d, List<List<Integer>> ans) {
        if (root == null) {
            return;
        }
        while (ans.size() <= d) {
            ans.add(new ArrayList<Integer>());
        }
        ans.get(d).add(root.val);
        doLevelOrder(root.left, d+1, ans);
        doLevelOrder(root.right, d+1, ans);
    }
}