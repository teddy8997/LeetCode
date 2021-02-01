/*
    題目為有[l,r]共n = r - l + 1的球，每個球放到對應的盒子裡面，對應方式是盒子的號碼等於球的每一個位數加起來
    例如123號球，就要放進1+2+3 = 6號盒子裡
    我們可以使用一個map來記錄總和出現次數就可以
    返回盒子中最多球的值
*/
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> m;
        int ans = 0;
        for(int i = lowLimit; i <= highLimit; i++){
            int n = i;
            int sum = 0;
            while(n){
                sum += n % 10;
                n = n / 10;
            }
            m[sum]++;
            ans = max(ans, m[sum]);
        }
        return ans;
    }
};