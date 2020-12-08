/*
    利用個變數來記錄上下左右邊界
    然後依次遍歷由左至右，由上到下，由右到左，由下到上
    在用邊界條件判斷如果超過邊界就是代表遍歷完成了
    time complexity: O(n)
    space complexity: O(1)

*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        while(true){
            for(int j = up; j <= right; j++){
                ans.push_back(matrix[up][j]);
            }
            if(++up > down){
                break;
            }
            for(int i = up; i <= down; i++){
                ans.push_back(matrix[i][right]);
            }
            if(--right < left){
                break;
            }
            for(int j = right; j >= left; j--){
                ans.push_back(matrix[down][j]);
            }
            if(--down < up){
                break;
            }
            for(int i = down; i >= up; i--){
                ans.push_back(matrix[i][left]);
            }
            if(++left > right){
                break;
            }
        }
        return ans;
    }
};