class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        //遍歷整個grid如果找到值為1的元素答案就+1
        //並且從那個點開始遞迴
        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                if(grid[y][x] == '1'){
                    ans += grid[y][x] - '0';
                    dfs(grid, x, y, m, n);
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n){
        //終止條件為超出上下左右範圍或是遇到值為0的就返回
        if(x < 0 || x >= n || y < 0 || y >= m || grid[y][x] == '0'){
            return;
        }
        grid[y][x] = '0';//否則就將值為1的島沉下去變為0
        //往上下左右走
        dfs(grid, x+1, y, m, n);
        dfs(grid, x-1, y, m, n);
        dfs(grid, x, y+1, m, n);
        dfs(grid, x, y-1, m, n);
    }
};