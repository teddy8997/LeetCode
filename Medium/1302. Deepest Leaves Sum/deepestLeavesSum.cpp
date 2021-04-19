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
    int deepestLeavesSum(TreeNode* root) {
        vector<vector<int>> levelOrderNode;
        levelOrder(root, 0, levelOrderNode);
        int ans = 0;
        for (auto n : levelOrderNode[levelOrderNode.size() - 1]) {
            ans += n;
        }
        return ans;
    }
    
private:
    void levelOrder(TreeNode *root, int d, vector<vector<int>> &levelOrderNode) {
        if (!root) {
            return;
        }
        while (levelOrderNode.size() <= d) {
            levelOrderNode.push_back({});
        }
        levelOrderNode[d].push_back(root->val);
        levelOrder(root->left, d+1, levelOrderNode);
        levelOrder(root->right, d+1, levelOrderNode);
    }
};