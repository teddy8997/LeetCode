class Solution {
    public int[][] merge(int[][] intervals) {
        LinkedList <int[]> tmp = new LinkedList<>();
        Arrays.sort(intervals, (a, b)-> Integer.compare(a[0], b[0]));
        tmp.add(intervals[0]);
        for(int i = 1; i < intervals.length; i++){
            if(tmp.isEmpty() || tmp.getLast()[1] < intervals[i][0]){
                tmp.add(intervals[i]);
            }else{
                tmp.getLast()[1] = Math.max(tmp.getLast()[1], intervals[i][1]);
            }
        }
        return tmp.toArray(new int[0][]);
    }
}