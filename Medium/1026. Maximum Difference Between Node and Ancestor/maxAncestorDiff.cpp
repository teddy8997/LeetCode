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
    這題的概念就是用dfs然後記錄最大及最小點的值
    time complexity: O(N)
*/
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root){
            return 0;
        }
        return dfs(root, INT_MAX,INT_MIN);
    }
private:
    int dfs(TreeNode* root, int mini_v, int max_v){
        if(!root){
            return max_v - mini_v;
        }
        max_v = max(max_v, root->val);
        mini_v = min(mini_v, root->val);
        int ans = max(dfs(root->left, mini_v, max_v), dfs(root->right, mini_v, max_v));
        return ans;
    }
};