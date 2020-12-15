/*
    參考https://www.youtube.com/watch?v=gdt7HQF56OI&ab_channel=LeadCoding
    
*/
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5,1));     
        for(int i = 2; i <= n; i++){
            int s = 0;
            for(int j = 0; j < 5; j++){
                s += dp[i-1][j];
                dp[i][j] = s;
            }
        }
        return accumulate(dp[n].begin(), dp[n].end(),0);
    }
};