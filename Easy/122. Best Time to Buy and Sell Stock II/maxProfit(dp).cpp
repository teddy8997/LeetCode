/*
    如果k為正無窮 就可以認為k和k-1是一樣的，可以改寫框架
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
                = max(dp[i-1][k][1], dp[i-1][k][0] - prices[i]);
    可以發現K已經不會改變了所以代表不需要紀錄K這個狀態了
    dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
    dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;
        for(int i = 0; i < n; i++){
            int tmp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, tmp - prices[i]);
        }
        return dp_i_0;
    }
};