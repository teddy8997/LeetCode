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
    法一: recursion
    利用反向的inorder來更新每個root中的值
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int pre = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right){
            bstToGst(root->right);
        }
        pre = pre + root->val;
        root->val = pre;
        if(root->left){
            bstToGst(root->left);
        }
        return root;
    }
};
/*
    法二:iterater

*/
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int curSum = 0;
        TreeNode* tmp = root;
        stack<TreeNode*> st;
        while(!st.empty() || tmp){
            if(tmp){
                st.push(tmp);
                tmp = tmp->right;
            }else{
                tmp = st.top();
                curSum += tmp->val;
                tmp->val = curSum;
                st.pop();
                tmp = tmp->left;
            }
        }
        return root;
    }
};