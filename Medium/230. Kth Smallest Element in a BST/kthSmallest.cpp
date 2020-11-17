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
        利用inorder訪問BST後會由小到大訪問的性質來做這題就完成了
        time complexity: O(n)
        space complexity: O(n)

*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tmp;
        inorder(root, tmp);
        return tmp[k-1];
    }
private:
    void inorder(TreeNode* root, vector<int> &tmp){
        if(!root){
            return;
        }
        inorder(root->left, tmp);
        tmp.push_back(root->val);
        inorder(root->right, tmp);
    }
};