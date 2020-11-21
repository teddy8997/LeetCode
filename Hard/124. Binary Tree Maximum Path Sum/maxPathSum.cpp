/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*

    Time complexity O(n)
    Space complexity O(h)
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
private:
    int maxPathSum(TreeNode* root, int &ans){
        if(!root){
            return 0;
        }
        int l = max(maxPathSum(root->left, ans), 0); //負值就不取了
        int r = max(maxPathSum(root->right, ans), 0);
        int sum = root->val + l + r;
        ans = max(ans, sum); //更新ans
        return max(l, r) + root->val;  //返回的話要返回單一路徑 我們取最大的
    }
};