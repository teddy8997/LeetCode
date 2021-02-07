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
    BFS解
    將所有子節點按照左右的順序放到下一層的Queue，這一層Queue的最後一個節點的值就是我們要找的直接放入答案
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return vector<int>();
        }
        queue<TreeNode*> q;
        vector<int> ans;
        
        q.push(root);
        while(!q.empty()){
            int qSize = q.size();
            for(int i = 1; i <= qSize; i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == qSize){
                    ans.push_back(node->val);
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                   q.push(node->right);
                }
            }
        }
        return ans;
    }
};