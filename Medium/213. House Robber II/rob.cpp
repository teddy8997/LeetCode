class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.empty()? 0 : nums[0];
        }
        //第一家和最後一家只能搶其中的一家或是都不搶，所以我們分別將第一家及最後一家去掉個算一遍能搶的最大值，較大的那個值則為答案
        return max(robb(nums, 0, nums.size()-1), robb(nums, 1, nums.size()));
    }
    int robb(vector<int>& nums, int left, int right){
        if(right - left <= 1){
            return nums[left];
        }
        //假設dp[i]為(0~i)能搶的最大值
        //若不搶狀態則為nums[i] + dp[i-2]
        //搶則為dp[i-1]
        //EX nums = {3,2,1,5}, dp[0] = 3, dp[1] = max(3, 2), dp[2] = max(nums[2] + dp[2-1], dp[i-1]) = 3 ... 以此類推
        vector<int> dp(right, 0);
        dp[left] = nums[left];
        dp[left+1] = max(nums[left], nums[left+1]);
        for(int i = left+2; i < right; i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp.back();
    }
};