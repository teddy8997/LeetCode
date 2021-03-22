/*
    遞迴+map記憶算過的值
*/
class Solution {
public:
    unordered_map<int, int> m;
    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        if(m[n]){
            return m[n];
        }
        m[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return m[n];
    }
};