/*
    題目要我們找出能在D天內完成的最小可能的搬運量
    代表我們的答案範圍在1 ~ sum(weights)中
    我們可以使用二分法
    如果m重量可以的話，代表他右邊以後的重量都可以滿足所以r = m
    反之則是l = m + 1
    那我們還需要一個輔助函式來判斷當前的重量是不是有符合答案
    time complexity: O(n * log(sum(weights)))
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int weightSum = 0;
        for(int i : weights){
            weightSum += i;
        }
        int l = 1;
        int r = weightSum;
        while(l < r){
            int m = l + (r - l) / 2;
            if(isValidWeight(weights, D, m)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return isValidWeight(weights, D, l)? l : r;
    }
private:
    bool isValidWeight(vector<int>& weights, int D, int shipWeight){
        int days = 0;
        int curWeight = 0;
        for(int i = 0; i < weights.size(); i++){
            if(weights[i] > shipWeight){
                return false;
            }
            if(weights[i] + curWeight > shipWeight){
                days++;
                curWeight = weights[i];
            }else{
                curWeight += weights[i];
            }
            if(days > D){
                return false;
            }
        }
        days++;
        return days <= D;
    }
};