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
    利用類似2分法的概念把中間的數當成ROOT後左邊就是左子樹右邊就是右子樹
    然後指標指好回傳ROOT就是答案
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size()-1);
    }
private:
    TreeNode* convert(vector<int>& nums, int l, int r){
        if(l > r){
            return nullptr;
        }
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = convert(nums, l, m-1);
        root->right = convert(nums, m+1, r);
        return root;
    }
};