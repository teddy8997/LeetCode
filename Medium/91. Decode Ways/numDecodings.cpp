/*
    這題主要有一些限制條件
    1. 一位數時不能為0
    2. 兩位數時不能大於26且其10位數不能大於2
    我們使用DP來解
    dp[i] 表示s字串中前i個字符組成的子串的解碼方法的個數
    那我們依據上面的條件去寫dp就可以了
    
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0'){
            return 0;
        }
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); i++){
            dp[i] = (s[i-1] == '0')? 0 : dp[i-1]; // 檢查前一位是不是0，如果是0代表現在這個位子只能單獨拆
            if(i > 1 && (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6')){
                dp[i] = dp[i] + dp[i-2];
            }
        }
        return dp.back();
    }
};