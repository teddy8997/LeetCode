class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
            minSum(x,y) = grid[y][x] + min(minSum(x-1, y), minSum(x,y-1))
            一個點的最小值為這個點的值加上 左邊格子的最小值和上面格子的最小值 兩者取最小的值
        */
        int m = grid.size();
        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
        s_ = vector<vector<int>>(m, vector<int>(n, 0));
        //求解到最右下的點(n-1, m-1)
        return minPathSum(grid, n-1, m-1, n, m);
    }
private:
    long minPathSum(vector<vector<int>>& grid, int x, int y, int n, int m){
        //到了起點就直接返回起點的值
        if(x == 0 && y == 0){
            return grid[y][x];
        }
        //超出邊界的話就特別處理返回最大值讓這個格子的值不會被用到
        if(x < 0 || y < 0){
            return INT_MAX;
        }
        //如果這個點已經求解過的話就直接返回這個點求解後的值
        if(s_[y][x] > 0){
            return s_[y][x];
        }
        //若這個點沒有求解過就進行求解
        int ans = grid[y][x] + min(minPathSum(grid, x-1, y, n, m), minPathSum(grid, x, y-1,n,m));
        //把解存到負責記錄的vector中
        return s_[y][x] = ans;
    }
    vector<vector<int>> s_;
};