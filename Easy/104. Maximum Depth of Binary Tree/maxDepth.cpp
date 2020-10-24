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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //這題和題目111很像 只是從找最小值改成找最大值
         if(!root){
            return 0;
        }
        if(!root->left && !root->right){
            return 1;
        }
        if(!root->left){
            return maxDepth(root->right) + 1;
        }
        if(!root->right){
            return maxDepth(root->left) + 1;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};