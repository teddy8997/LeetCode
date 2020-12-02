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
    Time complexity: O(n)
    Space complexity: O(n)
*/
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        prev_ = &dummy;
        inorder(root);
        return dummy.right;
    }
private: 
    TreeNode* prev_;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        prev_->right = root;
        prev_ = root;
        prev_->left = nullptr;
        inorder(root->right);
    }
};