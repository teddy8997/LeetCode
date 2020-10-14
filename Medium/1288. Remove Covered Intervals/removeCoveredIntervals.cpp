class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //題目是要移除範圍能夠被覆蓋的元素
        int ans = intervals.size();
        //先將區間從小排到大 那麼我們就只要比較結束的點就好
        sort(intervals.begin(), intervals.end(),[](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int maxEnd = intervals[0][1]; //將一開始結束的點初始化為第一個區間的結束點
        int del = 0;
        //從第二個區間開始比較，若是結束值小於前面的點的最大結束值代表這個區間被全覆蓋可以刪除
        //否則將最大結束值更新成新的區間
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][1] <= maxEnd){
               del++; 
            }else{
                maxEnd = intervals[i][1];
            }
        }
        //最後答案就是原本個數減掉要刪除的區間個數
        return ans - del;
    }
};