/*
    經典的DP問題，參考:https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-120-triangle/
    time complexity: O(n^2)
    space complxity: O(n^2)
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = triangle[i-1][j-1];
                if(i == 1 && j == 1){
                    continue;
                }
                if(j == 1){
                    dp[i][j] = dp[i][j] + dp[i-1][j];
                }else if(j == i){
                    dp[i][j] = dp[i][j] + dp[i-1][j-1];
                }else{
                    dp[i][j] = dp[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};