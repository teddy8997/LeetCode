class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                if(dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
       return dp[amount] == INT_MAX? -1 : dp[amount];
    }
};

/*
    base case: amount = 0 return 0
    狀態: 由於金幣量無限，面額也是題目給定，所以只有amount會不斷base case 靠近，所以狀態是amount
    選擇: 硬幣的種類
    定義dp(n): 輸入目標金額n，回傳湊出目標金額的最少硬幣個數 
    dp[n] = min(dp[n], dp[n-coin] + 1);
*/