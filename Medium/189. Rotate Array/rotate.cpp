class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*方法一
        vector<int> ans(nums.size(),0);
        for(int i = 0; i < nums.size(); i++){
            ans[(i + k) % nums.size()] = nums[i];
        }
        nums = ans;
        */
        //法二
        if(nums.empty() || (k %= nums.size()) == 0){
            return;
        }
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};