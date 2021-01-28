/*
    因為intervals已經是排序好的，所以我們可以先將end比newInterval.start還小的點加入到答案數組中
    直到遇到第一個end比newInterval.start還大的interval就可以開始合併
    合併方式為找出那些start比newInterval.end小或等於的interval一一合併
    接下來再把合併好的區間加入到答案數組
    接下來把剩下的interval加回答案數組中
    time complexity: O(n)
    spce complexity: O(1~n)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};