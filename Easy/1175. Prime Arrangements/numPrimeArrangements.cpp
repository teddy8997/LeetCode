/*
    參考:https://zxi.mytechroad.com/blog/math/leetcode-1175-prime-arrangements/
    time complexity: O(nsqrt(n))
    space complexity: O(1)
*/
class Solution {
public:
    int numPrimeArrangements(int n) {
        const int kMod = 1e9 + 7;
        int p = 0;
        for(int i = 1; i <= n; i++){
            p += isPrime(i);
        }
        long ans = 1;
        for(int i = 1; i <= p; i++){
            ans = (ans * i) % kMod;
        }
        for(int i = 1; i <= n - p; i++){
            ans = (ans * i) % kMod;
        }
        return ans;
    }
private:
    bool isPrime(int num){
        if(num < 2){
            return false;
        }
        if(num == 2){
            return true;
        }
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
};