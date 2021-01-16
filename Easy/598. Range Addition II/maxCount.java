class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int ResultR = m;
        int ResultC = n;
        for(int i = 0; i < ops.length; i++){
            ResultR = Math.min(ResultR, ops[i][0]);
            ResultC = Math.min(ResultC, ops[i][1]);
        }
        return ResultR * ResultC;
    }
}