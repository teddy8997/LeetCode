/*
    法一:recursion + DP

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < 0 || n < 0){
            return 0;
        }
        if(m == 1 && n == 1){
            return 1;
        }
        if(f_[m][n] > 0){
            return f_[m][n];
        }
        int left_path = uniquePaths(n-1, m);
        int up_path = uniquePaths(n, m-1);
        f_[m][n] = left_path + up_path;
        return f_[m][n];
    }
private:
    unordered_map<int,  unordered_map<int, int>> f_; 
};
/*
    法二: 迴圈 + DP
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        auto f = vector<vector<int>>(n+1, vector<int>(m+1,0));
        f[1][1] = 1;
        for(int y = 1; y <= n; y++){
            for(int x = 1; x <= m; x++){
                if(x == 1 && y == 1){
                    continue;
                }else{
                    f[y][x] = f[y-1][x] + f[y][x-1];
                }
            }
        }
        return f[n][m];
    }
};