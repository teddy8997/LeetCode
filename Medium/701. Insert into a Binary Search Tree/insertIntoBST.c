/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(!root){
        struct TreeNode *tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        tmp->val = val;
        tmp->left = tmp->right = NULL;
        return tmp;
    }
    if(root->val > val){
        root->left = insertIntoBST(root->left, val);
    }else{
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}