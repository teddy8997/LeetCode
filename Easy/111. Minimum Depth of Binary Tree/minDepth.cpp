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
    int minDepth(TreeNode* root) {
        //如果root是空的就回傳0
        if(!root){
            return 0;
        }
        //如果這個root沒有左子樹跟右子樹的話 回傳自己的深度1
        if(!root->left && !root->right){
            return 1;
        }
        //如果有左子樹或右子樹就繼續遍歷，沒有的話就回傳極大值以免被誤選用
        int l = root->left? minDepth(root->left) : INT_MAX;
        int r = root->right? minDepth(root->right) : INT_MAX;
        //回傳左子樹和右子樹取最小值後加上根節點的深度
        return min(l, r) + 1;
    }
};