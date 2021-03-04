/*
    PathSum: 給他一個節點和一個目標值，他回傳以這個節點為根的樹中，和為目標值的路徑總數
    count: 給他一個節點和目標值，返回以這個節點為根的樹中，能湊出幾個以該節點為路徑開頭，和為目標值的路徑總數

*/
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return 0;
        }
        int path = count(root, sum); //自己為開頭的路徑數
        int left = pathSum(root->left, sum); //左邊路徑總數
        int right = pathSum(root->right, sum); //右邊路徑總數
        return path + left + right;
    }
private:
    int count(TreeNode* root, int sum){
        if(root == nullptr){
            return 0;
        }
        int isMe = (root->val == sum)? 1 : 0; //判斷自己能不能自成一路
        int left = count(root->left, sum - root->val); //問左節點那邊能湊幾個sum - root->val
        int right = count(root->right, sum - root->val);//問右節點那邊能湊幾個sum - root->val
        return isMe + left + right;
    }