class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	//本題使用動態規劃
    	//建立一個dp[i] 表示到第i個前最大的subarray值
    	//狀態轉移方程式為 dp[i] = dp[i - 1] > 0? nums[i] + dp[i-1] : nums[i]
        //nums: [-2, 1, -3, 4, -1, 2, 1, -5, 4]
        //dp: 	[-2, 1, -2, 4,	3, 5, 6,  1, 5]
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};