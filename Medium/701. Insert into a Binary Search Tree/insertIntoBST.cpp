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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //簡單的BST插入問題，由於題目接受插入在最下層所以就選擇最簡單的方法插入

        //如果遞迴到空的NODE就NEW一個新節點插入
        if(!root){
            return new TreeNode(val);
        }
        //如果目前的NODE值比要插入的值大就往左子樹走
        if(root->val > val){
            root->left = insertIntoBST(root->left, val);
        }else{//如果目前的NODE值比要插入的值小就往右子樹走
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};