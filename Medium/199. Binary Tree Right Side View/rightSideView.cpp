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
    DFS解
    利用preorder的相反來訪問節點
    preorder的訪問順序為: 中左右
    我們可以變成中右左來確保先找rightmost的node，沒有的話在看左邊，都沒有的話代表這一層的右子樹是空的會去找左子樹
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, int d, vector<int>& ans){
        if(!root){
            return;
        }
        if(ans.size() <= d){
            ans.push_back(root->val);
        }
        dfs(root->right, d+1, ans);
        dfs(root->left, d+1, ans);
    }
};