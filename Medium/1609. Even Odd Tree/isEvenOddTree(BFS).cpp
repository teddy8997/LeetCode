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
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        int d = 0;
        while(!q.empty()){
            int N = q.size();
            int lastval;
            if(d % 2 == 0){
                lastval = INT_MIN;
            }else{
                lastval = INT_MAX;
            }
            for(int i = 0; i < N; i++){
                TreeNode* tmp = q.front();
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
                if(d % 2 == 0){
                    if(tmp->val % 2 == 0 || tmp->val <= lastval){
                        return false;
                    }
                }else{
                    if(tmp->val % 2 == 1 || tmp->val >= lastval){
                        return false;
                    }
                }
                lastval = tmp->val;
                q.pop();
            }
            d++;
        }
        return true;
    }
};