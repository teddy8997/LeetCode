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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> storeNode;
        storeNode.push(root);
        while(!storeNode.empty()){
            TreeNode *tmp = storeNode.top();
            storeNode.pop();
            ans.push_back(tmp->val);
            if(tmp->right){
                storeNode.push(tmp->right);
            }
            if(tmp->left){
                storeNode.push(tmp->left);
            }
        }
        return ans;
    }
};