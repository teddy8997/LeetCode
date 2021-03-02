/*
    time complexity: O(nlogn)
    space complexity: O(1)
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });       
        int count = 1;
        int end = intervals[0][1];
        for(vector<int> v : intervals){
            int start = v[0];
            if(start >= end){
                count++;
                end = v[1];
            }
        }
        return intervals.size() - count;
    }
};