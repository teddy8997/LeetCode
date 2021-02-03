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
    比較三種狀況
    1. L <= a <= R 
    2. a < L 
    3. a > R
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
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
};