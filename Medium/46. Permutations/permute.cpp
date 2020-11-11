/*
    Time complexity: O(n!)
    Space complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> visited(nums.size());
        permutation(nums, ans, cur, visited, 0);
        return ans;
    }
private:
    void permutation(vector<int>& nums, vector<vector<int>> &ans, vector<int> &cur, vector<int> &visited, int s){
        if(s == nums.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1){
                continue;
            }
            visited[i] = 1;
            cur.push_back(nums[i]);
            permutation(nums, ans, cur, visited, s+1);
            cur.pop_back();
            visited[i] = 0;
        }
    }
};