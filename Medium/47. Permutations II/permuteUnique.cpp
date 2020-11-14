/*
    這題和46.Permutations比起來差別在他的數列裡有重複的數字
    所以最後出來的答案會有重複的數組
    我們只需要利用SET把重複的vector移除就是答案
    time complexity: O(n!)
    space complexity: O(n)

*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> visited(nums.size());
        permutation(nums, ans, cur, visited, 0);
        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> removeDupAns(s.begin(), s.end());
        return removeDupAns;
    }
private:
    void permutation(vector<int>& nums, vector<vector<int>> &ans, vector<int> &cur, vector<int> &visited, int d){
        if(d == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]){
                continue;
            }
            visited[i] = 1;
            cur.push_back(nums[i]);
            permutation(nums, ans, cur, visited, d+1);
            cur.pop_back();
            visited[i] = 0;
        }
    }
};