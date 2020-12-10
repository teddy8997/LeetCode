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
    法一
    這題是考BST使用iterator的中序訪問，中序訪問依序是左->中->右，而BST使用中序訪問就是代表由小到大訪問
    我們需要使用一個stack來進行輔助

*/

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) { //初始化由root開始的左子樹都push到stack中，此時stack最上面的數就會是這棵BST中最小的
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *n = s.top();
        s.pop();
        int res = n->val; //stack最上面的值是我們要返回的答案
        if (n->right) {//檢查看看當前的root是否有右子樹
            n = n->right;
            while (n) {//有的話將右子樹push到stack中，並將此柚子樹的所有左子樹push到stack中
                s.push(n);
                n = n->left;
            }
        }
        return res;
    }
    
    bool hasNext() {
        return !s.empty(); //檢查有無下一個點時只需要檢查stack是否為空的就行
    }
    
private:
    stack<TreeNode*> s;
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

/*
    法二
*/
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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }
    /** @return the next smallest number */
    int next() {
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        int ans = cur->val;
        cur = cur->right;
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
       return cur || !s.empty();
    }
    
private:
    stack<TreeNode*> s;
    TreeNode* cur;
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 