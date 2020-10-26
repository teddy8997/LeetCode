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
    /*
        利用DFS
        然後利用深度d來把同一深度的node加到當前深度的vector中
        Time complextity: O(n)
    */
/*
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        level(root, 0, ans);
        return ans;
    }
private:
    void level(TreeNode *root, int d, vector<vector<int>> &ans){
        if(!root){
            return;
        }
        while(ans.size() <= d){
            ans.push_back({});
        }
        ans[d].push_back(root->val);
        level(root->left, d+1, ans);
        level(root->right, d+1, ans);
    }
    */
    /*
        BFS
    */
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        cur.push_back(root);
        while(!cur.empty()){
            ans.push_back({});
            for(TreeNode* node : cur){
                ans.back().push_back(node->val);
                if(node->left){
                    next.push_back(node->left);
                }
                if(node->right){
                    next.push_back(node->right);
                }
            }
            cur.swap(next);
            next.clear();
        }
        return ans;
    }
};