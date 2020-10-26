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
    /*
        根據BST的定義來解就行了.
        Time complexity: O(n)
        Space complexity: O(n)
    */
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool isValid(TreeNode* root, long min_val, long max_val){
        if(!root){
           return true; 
        }
        if(root->val <= min_val || root->val >= max_val){
            return false;
        }
        return isValid(root->left, min_val, root->val) && isValid(root->right, root->val, max_val);
    }
};