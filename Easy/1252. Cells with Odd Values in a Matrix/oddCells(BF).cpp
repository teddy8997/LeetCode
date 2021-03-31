class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> tmp(n, vector<int>(m, 0));
        for(auto i : indices){
            for(int x = 0; x < m; x++){
                tmp[i[0]][x]++;
            }
            for(int y = 0; y < n; y++){
                tmp[y][i[1]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(tmp[i][j] % 2){
                    ans++;
                }
            }
        }
        return ans;
    }
};