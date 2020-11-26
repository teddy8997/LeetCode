class Solution {
    public int[][] transpose(int[][] A) {
        int m = A.length;
        int n = A[0].length;
        int [][] ans = new int [n][m];
        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                ans[x][y] = A[y][x];
            }
        }
        return ans;
    }
}