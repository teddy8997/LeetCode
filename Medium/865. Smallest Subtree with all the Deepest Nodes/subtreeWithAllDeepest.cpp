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
    time complexity: O(n)
    space complexity: O(n)
    解題詳情請參考:http://zxi.mytechroad.com/blog/tree/leetcode-865-smallest-subtree-with-all-the-deepest-nodes/
*/
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return depth(root).second;    
    }
private:
    pair<int, TreeNode*> depth(TreeNode* root){
        if(!root){
            return {-1, nullptr};
        }
        auto l = depth(root->left);
        auto r = depth(root->right);
        int dL = l.first;
        int dR = r.first;
        return {max(dL, dR) + 1, dL == dR? root : (dL > dR)? l.second : r.second};
    }
};