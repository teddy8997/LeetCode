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
    這題很明顯可以利用回溯法來做，當前的計算結果需要依靠之前計算的結果，對於一個節點如果左節點存在透過遞迴算出不包含左子節點返回的值
    如果右節點存在算出不包括右子節點的值。那麼此節點的最大值可能有想種情形，第一種是當前的節點值加上不包含左子節點和右子節點的返回值之和
    第二種是左右子節點返回值不包含當前節點
    取兩者最大值返回即可
    我們可以利用MAP把計算過的節點存起來加快速度
    Time complexity: O(n)
    Space complexity: O(n)

*/
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return dfs(root, m);
    }
private:
    int dfs(TreeNode* root, unordered_map<TreeNode*, int> &m){
        if(!root){
            return 0;
        }
        if(m.count(root)){
            return m[root];
        }
        int val = 0;
        if(root->left){
            val += dfs(root->left->left, m) + dfs(root->left->right,m);
        }
        if(root->right){
            val += dfs(root->right->left, m) + dfs(root->right->right, m);
        }
        val = max(val + root->val, dfs(root->left,m) + dfs(root->right,m));
        m[root] = val;
        return val;
    }
};