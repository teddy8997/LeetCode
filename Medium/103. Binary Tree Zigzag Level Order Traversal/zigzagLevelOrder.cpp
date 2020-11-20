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
    這題我覺得可以是102. Binary Tree Level Order Traversal的變形題
    先求出level order然後將index 1, 3, 5....的vector reverse就是答案
    time complexity: O(n)
    space complexity: O(n)

*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, 0, ans);
        for(int i = 1; i < ans.size(); i += 2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
private:
    void levelOrder(TreeNode* root, int d, vector<vector<int>> &ans){
        if(!root){
            return;
        }
        while(ans.size() <= d){
            ans.push_back({});
        }
        ans[d].push_back(root->val);
        levelOrder(root->left, d+1, ans);
        levelOrder(root->right, d+1, ans);
    }
};