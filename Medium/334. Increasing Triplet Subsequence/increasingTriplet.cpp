/*
    解法使用Greedy
    用兩個變數分別記錄兩個較小的數，如果能找到比這兩個數都大的數就返回true
    我們先將min1, min2 都設為最大值
    然後當當前的數n小於min1時 min1 = n
    當當前的數n介於min1和min2時 min2 = n
    如果當前的n大於min2代表找到符合題目條件的三個數了

    如果迴圈完成之後還沒有找到就返回false
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int n : nums){
            if(n > min2){
                return true;
            }else if(n < min1){
                min1 = n;
            }else if(n > min1 && n < min2){
                min2 = n;
            }
        }
        return false;
    }
};