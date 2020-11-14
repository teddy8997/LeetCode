/*
    Time complexity: O(C(n, k))
    Space complexity: O(k)
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        combination(n, k, ans, cur, 1);
        return ans;
    }
private:
    void combination(int n, int k, vector<vector<int>> &ans, vector<int> &cur, int s){
        if(cur.size() == k){
            ans.push_back(cur);
            return;
        }
        for(int i = s; i <= n; i++){
            cur.push_back(i);
            combination(n, k, ans, cur, i+1);
            cur.pop_back();
        }
    }
};