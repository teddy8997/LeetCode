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
    簡單的一提利用DFS訪問每個NODE並判斷他的值是否在low <= node->val <= high中
    如果是就加到sum中
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        DFS(root, low, high, sum);
        return sum;
    }
private:
    void DFS(TreeNode* root, int low, int high, int &sum){
        if(!root){
           return; 
        }
        if(root->val >= low && root->val <= high){
            sum += root->val;
        }
        DFS(root->left, low, high, sum);
        DFS(root->right, low, high, sum);
    }
};