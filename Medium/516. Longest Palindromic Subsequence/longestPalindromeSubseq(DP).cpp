        //假設dp數組定義為 array[i...j] 中，我們要求的最長子序列的長度為dp[i][j]
        //? b   x   a   b   y     ?
        //i i+1             j-1   j
        //我們要找狀態怎麼轉移，可以從dp[i+1][j-1]來推dp[i][j]的值
        //當s[i] == s[j]時，轉移方程式就是dp[i+1][j-1]+2
        //當s[i] != s[j]時，轉移方程式就是max(dp[i+1][j], dp[i][j-1])
        //我們要求的就是dp[0][n-1]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
        }
        for(int i = n - 1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                if(s[i] != s[j]){
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};