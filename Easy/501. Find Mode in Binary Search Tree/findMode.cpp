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
    利用map記錄每個數字出現幾次，並在遍歷的時候紀錄最多的出現次數
    最後全部遍歷完後再從MAP中找有同樣最大出現次數的數值出來
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
       
        vector<int> ans;
        int countMax = 0;
        inorder(root, countMax);
        for(auto v : m){
            if(v.second == countMax){
                ans.push_back(v.first);
            }
        }
        return ans;
    }
private:
    unordered_map<int, int> m;
    void inorder(TreeNode* root, int &countMax){
        if(!root){
            return;
        }
        inorder(root->left, countMax);
        countMax = max(countMax, ++m[root->val]);
        inorder(root->right, countMax);
    }
};