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
    參考: HUAHUA

*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }else{ //如果找到目標Node要處理三種情況
            if(root->left != nullptr && root->right != nullptr){ //第一種情況左右子樹都有，可以找左子樹的最大值或是右子樹的最小值來接替
                TreeNode *min = root->right;
                while(min->left){
                    min = min->left;
                }
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }else{ //第二種及第三種，只有一個子樹或是都沒有子樹
                TreeNode *new_root = root->left == nullptr? root->right : root->left;
                root->left = root->right = nullptr;
                delete root;
                return new_root;
            }
        }
        return root;
    }
};