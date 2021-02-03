/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* trimBST(struct TreeNode* root, int low, int high){
    if(!root){
        return root;
    }
    if(root->val < low){
        return root = trimBST(root->right, low, high);
    }
    if(root->val > high){
        return root = trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}