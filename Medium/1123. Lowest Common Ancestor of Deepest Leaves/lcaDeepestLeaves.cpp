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
    這題和865.Smallest Subtree with all the Deepest Nodes 解法一模一樣
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return deepest(root).second;
    }
private:
    pair<int, TreeNode*> deepest(TreeNode* root){
        if(!root){
            return {-1, nullptr};
        }
        pair<int, TreeNode*> L = deepest(root->left);
        pair<int, TreeNode*> R = deepest(root->right);
        int dL = L.first;
        int dR = R.first;
        return {max(dL, dR) + 1, dL == dR ? root : (dL > dR) ? L.second : R.second};
    }
};