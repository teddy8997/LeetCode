/*
    利用preorder順序
    先將root的左子樹連到右子樹，再判斷root->next是否存在若存在再把右子樹連到root->next的左子樹
    time complexity: O(n)
    space complexity: O(log(n))
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root || !root->left){
            return root;
        }
        root->left->next = root->right;
        if(root->next){
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};