/*
    使用DP來解
    dp[i][k]: 到第 i 個字符為止第i個字符是字母k的方案數
    根據提議第i-1個字符必須小於等於k
    最後我們要求的結果為 sum{dp[n-1][k]}, k = 0,1,2,3,4
    
*/
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5));    
        for(int k = 0; k < 5; k++){
            dp[0][k] = 1;
        }
        
        for(int i = 1; i < n; i++){
            for(int k = 0; k < 5; k++){
                for(int j = 0; j <= k; j++){
                    dp[i][k] += dp[i-1][j];
                }
            }
        }
        return accumulate(dp[n-1].begin(), dp[n-1].end(),0);
    }
};