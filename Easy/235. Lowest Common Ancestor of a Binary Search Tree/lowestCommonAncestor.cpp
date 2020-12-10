/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
   一個給定的root，遞迴他的左子樹 及右子樹
   如果兩個都回傳一個非空的節點 代表p q在不同的子樹中，所以root就是答案
   如果只有其中一個非空則代表他們在同一個子樹中，所以回傳非空的答案
    Time complexity: O(n)
    Space complexity: O(h)
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q){
            return root;
        }
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        if(l && r){
            return root;
        }
        return l? l : r;
    }
};