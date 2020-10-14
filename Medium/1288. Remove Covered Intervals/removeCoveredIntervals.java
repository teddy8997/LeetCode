class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals,(e1, e2)->{
            if(e1[0] == e2[0]){
                return e2[1] - e1[1];
            }
            return e1[0] - e2[0];
        });
        int maxEnd = intervals[0][1];
        int ans = intervals.length;
        for(int i = 1; i < intervals.length; i++){
            if(intervals[i][1] <= maxEnd){
                ans--;
            }else{
                maxEnd = intervals[i][1];
            }
        }
        return ans;
    }
}