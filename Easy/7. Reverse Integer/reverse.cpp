class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int r = x % 10;
            //檢查*10之前 是不是就大於INT最大值 / 10 了 如果大於 * 10後就會超過範圍
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10){
                return 0;
            }
            ans = ans * 10 + r;
            x = x / 10;          
        }
        return ans;
    }
};