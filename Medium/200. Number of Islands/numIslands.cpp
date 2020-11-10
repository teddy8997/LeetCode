/*
    Time complexity: O(m * n)
    Space complexity: O(m * n)
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                /*
                    主要想法就是遇到1的就計算有一個島
                    並從這個1開始延伸把連著這個島的都沉下去變成0
                */
                if(grid[y][x] == '1'){
                    ans++;
                    check(grid, x, y, n, m);
                }
            }
        }
        return ans;
    }
private:
    void check(vector<vector<char>>& grid, int x, int y, int n, int m){
        if(x < 0 || x >= n || y < 0 || y >= m || grid[y][x] == '0'){
            return;
        }
        grid[y][x] = '0';
        check(grid, x + 1, y, n, m);
        check(grid, x - 1, y, n, m);
        check(grid, x, y + 1, n, m);
        check(grid, x , y - 1, n, m);
    }
};