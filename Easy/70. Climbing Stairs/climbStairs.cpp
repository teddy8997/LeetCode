class Solution {
public:
    int climbStairs(int n) {
    	/*
			最簡單的dp,先初始化dp[0]都不走也算一種解
			dp[1]走一步一種解
			因為可以
			1. 1走一步到2
			2. 0走兩步到2
			所以2的解為dp[2] = dp[0] + dp[1]
			也就是dp[i] = dp[i-1] + dp[i-2]
			time complexity: O(n)
    	*/
        vector<int> dp(n+1,0);
        dp[0] = 1; 
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};