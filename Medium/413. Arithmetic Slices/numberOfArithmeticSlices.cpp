/*
    使用DP，DP[i]表示到位置i為止的Arithmetic Slice總數
    轉移方程式則是如果A[i] - A[i - 1] == A[i-1] - A[i - 2]則使用前一個的數量dp[i] = dp[i - 1] + 1
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 2; i < n; i++){
            if(A[i] - A[i - 1] == A[i-1] - A[i - 2]){
                dp[i] = dp[i - 1] + 1;
            }
            ans += dp[i]; 
        }
        return ans;
    }
};