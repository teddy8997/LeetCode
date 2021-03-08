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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> count;
        vector<double> ans;
        DFS(root, 0, count, ans);
        for(int i = 0; i < ans.size(); i++){
            ans[i] = ans[i] / count[i];
        }
        return ans;
    }
private:
   
    void DFS(TreeNode* root, int d, vector<int> &count, vector<double> &ans){
        if(!root){
            return;
        }
        while(d >= ans.size()){
            ans.push_back(0);
            count.push_back(0);
        }
        ans[d] = ans[d] + root->val;
        count[d] = count[d] + 1;
        DFS(root->left, d + 1, count, ans);
        DFS(root->right, d + 1, count, ans);
    }
};