class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        for(int i = 0; i <= nums.size(); i++){
            combi(nums, i, 0, cur, ans);
        }
        return ans;
    }
private:
    void combi(vector<int>& nums, int n, int s, vector<int> &cur, vector<vector<int>> &ans){
        if(n == cur.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = s; i < nums.size(); i++){
            cur.push_back(nums[i]);
            combi(nums, n, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};