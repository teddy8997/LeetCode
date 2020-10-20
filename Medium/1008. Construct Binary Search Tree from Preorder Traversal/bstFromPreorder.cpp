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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //建立bst 從index 0 ~ n
        return build(preorder, 0, preorder.size());
    }
private:
    TreeNode* build(vector<int>& preorder, int s, int e){
        //當前面的index已經超過後面的index回傳空指針
        if(s >= e){
            return nullptr;
        }
        //建立一個新節點 並且以那個節點開始在preorder的vector中
        //使用一個變數m來紀錄比當前節點還小的數到哪個index
        auto root = new TreeNode(preorder[s]);
        int m = s;
        while(m < e && preorder[m] <= root->val){
            m++;
        }
        //比當前root還小的節點就是左子樹，然後遞迴範圍是當前節點的index s + 1 到 m
        root->left = build(preorder, s+1, m);
         //比當前root還大的節點就是右子樹，然後遞迴範圍是index m 到 最後e
        root->right = build(preorder, m, e);
        return root;
    }
};