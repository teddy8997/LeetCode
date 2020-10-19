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
//觀察發現只會有一個轉折節點可以左右子樹都有走過
//所以只要記錄每個點使用左右子樹的最大路徑長度就可以了
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans_ = 0;
        DoT(root);
        return ans_;
    }
private:
    int ans_;
    int DoT(TreeNode *root){
        if(!root){
            return -1;
        }
        int l = DoT(root->left) + 1; //左子樹到root的路徑長度
        int r = DoT(root->right) + 1; //右子樹到root的路徑長度
        ans_ = max(ans_, l+r); //當轉折點同時使用左右子樹
        return max(l,r);//作為非轉折節點取左右子樹中最大的+1
    }
};