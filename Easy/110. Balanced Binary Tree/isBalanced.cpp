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
    利用一個變數來記錄每一層的左右子樹是否平衡
    如果不平衡的話就設定成false然後返回

    平衡數的條件是:
	1.左子樹是平衡的
	2.右子樹是平衡的
	3.左右子樹的高度差不大於1

    time complexity: O(N)
    Space complexity: O(1) 最差情況下是O(N)
*/
class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        Check(root);
        return ans;
    }
private:
    int Check(TreeNode* root){
        if(!root || !ans){
            return 0;
        }
        int l = Check(root->left);
        int r = Check(root->right);
        if(abs(l - r) > 1){
            ans = false;
            return 0;
        }
        return max(l, r) + 1;
    }
};