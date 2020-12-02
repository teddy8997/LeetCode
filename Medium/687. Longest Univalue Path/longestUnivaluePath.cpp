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
 *
 /*
    Time complexity: O(n)
    Space complexity: O(n)
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = 0;
        check(root,&ans);
        return ans;
    }
private:
    int check(TreeNode* root, int *ans){
        if(!root){
            return 0;
        }
        int l = check(root->left, ans);
        int r = check(root->right, ans);
        int pl = 0;
        int pr = 0;
        if(root->left && root->val == root->left->val){
            pl = 1 + l;
        }
        if(root->right && root->val == root->right->val){
            pr = 1 + r;
        }
        *ans = max(*ans, pl + pr); //因為有可能有沒有通過最上面跟節點的情形 如題目給的例子2，所以更新答案時要注意
        return max(pl, pr); // 然後我們返回不能返回同時使用左右子樹後的最大深度，所以我們取其中一個最大返回
    }
};