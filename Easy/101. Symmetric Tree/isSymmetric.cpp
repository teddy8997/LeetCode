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
    使用同時兩次遍歷
    如果root1和root2同時都是null的話就返回true
    反之則代表他們沒有對稱返回false
    最後比較root1及root2的值有沒有相等 而且他們鏡像的位置有沒有相等
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        return root1->val == root2->val &&  isSymmetric(root1->left, root2->right)
            && isSymmetric(root1->right, root2->left);
    }
};