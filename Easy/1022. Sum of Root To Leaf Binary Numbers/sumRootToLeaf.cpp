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
    time complexit: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        int tmpSum = 0;
        sum(root, ans, tmpSum);
        return ans;
    }
private:
    void sum(TreeNode* root, int &ans, int tmpSum){
        tmpSum = tmpSum * 2 + root->val;
        if(root->left){
            sum(root->left, ans, tmpSum);
        }
        if(root->right){
            sum(root->right, ans, tmpSum);
        }
        if(!root->right && !root->left){
            ans += tmpSum;
        }
    }