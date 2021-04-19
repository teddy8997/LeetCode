class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int m = matrix.length;
        int n = matrix[0].length;
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        while (true) {
            for (int j = up; j <= right; j++) {
                ans.add(matrix[up][j]);
            }
            if (++up > down) {
                break;
            }
            for (int i = up; i <= down; i++) {
                ans.add(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }
            for (int j = right; j >= left; j--) {
                ans.add(matrix[down][j]);
            }
            if (--down < up) {
                break;
            }
            for (int i = down; i >= up; i--) {
                ans.add(matrix[i][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return ans;
    }
}