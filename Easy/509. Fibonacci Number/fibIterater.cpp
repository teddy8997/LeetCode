/*
    迴圈解法
    主要以bottom up為想法
    初始化最前面的值慢慢推導出目標的值
*/
class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};