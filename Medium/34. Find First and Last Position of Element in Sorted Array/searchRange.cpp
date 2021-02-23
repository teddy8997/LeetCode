class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> ans;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] < target){
                l = m + 1;
            }else if(nums[m] > target){
                r = m - 1;
            }else if(nums[m] == target){
                r = m - 1;
            }
        }
        if(l >= nums.size() || nums[l] != target){
            ans.push_back(-1);
        }else{
            ans.push_back(l);
        }

        l = 0;
        r = nums.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] < target){
                l = m + 1;
            }else if(nums[m] > target){
                r = m - 1;
            }else if(nums[m] == target){
                l = m + 1;
            }
        }
        if(r < 0 || nums[r] != target){
            ans.push_back(-1);
        }else{
            ans.push_back(r);
        }
        return ans;
    }
};