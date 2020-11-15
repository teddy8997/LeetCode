/*
	先以對角線為軸翻轉 再以X軸中線為軸上下翻轉即可得到答案
	time complexity: O(n^2)
	space complexity: O(1)
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i; j++){
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 -i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};