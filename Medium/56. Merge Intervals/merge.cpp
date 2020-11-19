/*
    先將起點從小到大排序後再倆倆比較第一個終點有沒有比第二個終點小 如果比較小代表兩個點沒有交集
    比較大代表兩個點有交集然後比較各自的結尾誰比較大
    time complexity: O(n*log(n))
    space complexity: O(n)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[0] < b[0];});
        vector<vector<int>> ans{intervals[0]};
        for(int i = 1; i < intervals.size(); i++){
            if(ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};