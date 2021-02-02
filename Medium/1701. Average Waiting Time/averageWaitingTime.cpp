/*
    記錄前一個最後完成時間，如果下一個的開始時間小於這個時間代表他要等前一個的最後完成時間+準備自己餐的時間
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int t = 0;
        double w = 0;
        for(vector<int> c : customers){
            if(c[0] > t){
                t = c[0];
            }
            t += c[1];
            w += t - c[0];
        }
        return w / customers.size();
    }
};