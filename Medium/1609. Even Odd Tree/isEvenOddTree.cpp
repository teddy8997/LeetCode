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
    用深度d 當作index來記錄每一層的最後訪問到的點的值
    每到一個新的點就檢查題目所要的條件
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<int> v;
        return dfs(root, v, 0); 
    }
private:
    bool dfs(TreeNode* root, vector<int> &v, int d){
        if(!root){
            return true;
        }
        if(v.size() <= d){
            v.push_back(d % 2 == 0? -1 : INT_MAX);
        }
        int value = v[d];
        if(d % 2 == 0){
            if(root->val % 2 == 0 || root->val <= value){
                return false;
            }
        }
        if(d % 2 == 1){
            if(root->val % 2 == 1 || root->val >= value){
                return false;
            }
        }
        v[d] = root->val;
        return dfs(root->left, v, d+1) && dfs(root->right, v, d+1);
    }
};