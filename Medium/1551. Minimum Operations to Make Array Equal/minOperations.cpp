class Solution {
public:
    int minOperations(int n) {
        int max = 2 * (n - 1) + 1;
        int avg = (1 + max) / 2;
        int ans = 0;
        for (int i = 0; i < n/2; i++) {
            int num = 2 * i + 1;
            ans += avg - num;
        }
        return ans;
    }
};