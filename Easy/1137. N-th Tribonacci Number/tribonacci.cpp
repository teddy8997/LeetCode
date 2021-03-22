class Solution {
public:
    int tribonacci(int n) {
        vector<int> tmp(38);
        tmp[0] = 0;
        tmp[1] = 1;
        tmp[2] = 1;
        for(int i = 3; i <= n; i++){
            tmp[i] = tmp[i - 1] + tmp[i - 2] + tmp[i - 3];
        }
        return tmp[n];
    }
};