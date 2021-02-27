/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValid(struct TreeNode* root, long max_v, long min_v);

bool isValidBST(struct TreeNode* root){
    return isValid(root, LLONG_MAX, LLONG_MIN);
}
bool isValid(struct TreeNode* root, long max_v, long min_v){
        if(!root){
            return true;
        }
        if(root->val >= max_v || root->val <= min_v){
            return false;
        }
        return isValid(root->left, root->val, min_v) && isValid(root->right, max_v, root->val);    
}