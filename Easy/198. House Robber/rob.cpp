class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.empty()? 0 : nums[0];
        }
        ////假設dp[i]為(0~i)能搶的最大值
        //若不搶狀態則為nums[i] + dp[i-2]
        //搶則為dp[i-1]
        //EX nums = {3,2,1,5}, dp[0] = 3, dp[1] = max(3, 2), dp[2] = max(nums[2] + dp[2-1], dp[i-1]) = 3 ... 以此類推
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp.back();
    }
};