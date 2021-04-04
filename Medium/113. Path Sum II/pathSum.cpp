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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        vector<vector<int>> ans;
        pathSum(root, targetSum, cur, ans);
        return ans;
    }
private:
    void pathSum(TreeNode *root, int sum, vector<int> &cur, vector<vector<int>> &ans) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum) {
                cur.push_back(root->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        cur.push_back(root->val);
        int newSum = sum - root->val;
        pathSum(root->left, newSum, cur, ans);
        pathSum(root->right, newSum, cur, ans);
        cur.pop_back();
    }
};