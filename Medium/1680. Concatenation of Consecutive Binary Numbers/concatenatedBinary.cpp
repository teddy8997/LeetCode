/*
    n = 1, 1
    n = 2, 1 10
    n = 3, 110 11
    n = 4, 11011 100
    所以可以觀察到
    答案為 (n-1 << len) + n
    len則是觀察發現長度為 (i % 2) + 1
    
*/
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 1;
        constexpr int kMod = 1e9 +7;
        for(int i = 2; i <= n; i++){
            int len = log(i) / log(2) + 1;
            ans = ((ans << len) + i) % kMod;
            ans = ans % kMod;
        }
        return ans;
    }
};