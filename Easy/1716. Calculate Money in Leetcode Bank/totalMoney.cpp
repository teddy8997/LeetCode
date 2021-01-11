/*
    每天增加1，然後每個星期天減去6
    
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int totalMoney(int n) {
        int totalMoney = 0;
        int m = 1;
        for(int i = 0; i < n; i++){
            totalMoney += m++;
            if(i % 7 == 6){
                m -= 6;
            }
        }
        return totalMoney;
    }
};