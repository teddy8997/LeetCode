/*
    利用一個table來記錄算過的結果
*/
class Solution {
public:
    int fib(int n) {
       if(n < 1){
           return 0;
       }
        vector<int> memo(n+1, 0);
        return f(n, memo);
    }
    int f(int n, vector<int> &memo){
        if(n == 1 || n == 2){
            return 1;
        }
        if(memo[n] != 0){
            return memo[n];
        }
        memo[n] = f(n-1, memo) + f(n-2, memo);
        return memo[n];
    }
};