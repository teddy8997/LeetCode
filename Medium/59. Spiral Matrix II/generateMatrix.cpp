/*
    這題和54.Spiral Matrix解法一模一樣
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int indexM = n - 1;
        int indexN = n - 1;
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        int count = 1;
        while(true){
            for(int j = left; j <= right; j++){
                ans[up][j] = count;
                count++;
            }
            if(++up > down){
                break;
            }
            for(int i = up; i <= down; i++){
                ans[i][right] = count;
                count++;
            }
            if(--right < left){
                break;
            }
            for(int j = right; j >= left; j--){
                ans[down][j] = count;
                count++;
            }
            if(--down < up){
                break;
            }
            for(int i = down; i >= up; i--){
                ans[i][left] = count;
                count++;
            }
            if(++left > right){
                break;
            }
        }
        return ans;
    }
};