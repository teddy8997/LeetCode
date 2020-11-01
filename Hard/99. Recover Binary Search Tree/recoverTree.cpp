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
    void recoverTree(TreeNode* root) {
        /*
            這題想法就是BST使用inorder訪問的時候節點的值會由小到大排序
            利用這個想法我們先用一個vector紀錄inorder依序訪問的節點位址
            再利用一個vector紀錄inorder後的值，但這邊的值不會由小到大 因為題目說有兩個節點的值是錯的
            所以我們再將這個存值的vector依照正確順序小到大排好
            再把正確的值依序存給原本inorder的節點
            space complexity: O(n)
        */
        vector<TreeNode*> list;
        vector<int> vals;
        inorder(root, list, vals);
        sort(vals.begin(), vals.end());
        for(int i = 0; i < list.size(); i++){
            list[i]->val = vals[i];
        }
    }
    void inorder(TreeNode* root, vector<TreeNode*> &list, vector<int> &vals){
        if(!root){
            return;
        }
        inorder(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        inorder(root->right, list, vals);
    }
};