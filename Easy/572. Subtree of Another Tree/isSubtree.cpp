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
    先從s的根節點開始與t比較如果兩棵樹完全相同返回true，不相同就分邊對s的左節點及右節點使用遞迴來再次判斷是否相同
    只要有一個返回true就表示可以找的到
    
*/
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s){
            return false;
        }
        if(isSame(s, t)){
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool isSame(TreeNode* s, TreeNode *t){
        if(!s && !t){
            return true;
        }
        if(!s || !t){
            return false;
        }
        if(s->val != t->val){
            return false;
        }
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};