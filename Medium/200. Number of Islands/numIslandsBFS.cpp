class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<int> offset{0, 1, 0, -1, 0};
        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                if(grid[y][x] == '1'){
                    ans++;
                    grid[y][x] = '0';
                    
                    queue<pair<int, int>> q;
                    q.push({y, x});
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++){
                            int r = p.first + offset[k];
                            int c = p.second + offset[k+1];
                            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1'){
                                grid[r][c] = '0';
                                q.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};