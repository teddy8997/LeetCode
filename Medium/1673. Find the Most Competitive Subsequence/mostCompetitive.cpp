class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans(k);
        int idx = 0;
        int rem = nums.size() - k;
        for(int i = 0; i < nums.size(); i++){
            while(idx > 0 && ans[idx - 1] > nums[i] && rem > 0){
                idx--;
                rem--;
            }
            if(idx < k){
                ans[idx++] = nums[i];
            }else{
                rem--;
            }
        }
        return ans;
    }
};