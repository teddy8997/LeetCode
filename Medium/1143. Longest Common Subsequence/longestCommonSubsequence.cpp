/*
    第一步定義dp:在子數組arr1[0...i]，和子數組arr2[0..j]，我們要求的子序列長度為dp[i][j], 最後要得到的答案為dp[i][j]
    第二步定義base case: 索引為0的行和列表示空串，dp[0][..] dp[..][0]都應該初始化為0
    第三步找狀態轉移方程式:這個問題主要是在求s1和s2的最長公共子序列，對於s1及s2有什麼選擇?
    主要有兩種選擇要嘛不在最長公共子序列中，要嘛在。所以我們用兩個指針i,j由後往前遍歷s1和s2，如果s1[i] == s2[j]那這個字符一定在最長公共子序列中
    否則s1[i] s2[j] 至少會有一個不在最長公共子序列中
    
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};