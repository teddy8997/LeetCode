/*
    將矩陣轉置矩陣會從原本的m*n變成n*m所以我們創一個新的矩陣來存轉置後的值
    Time complexity: O(mn)
    Space complexity: O(mn)
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                ans[x][y] = A[y][x]; 
            }
        }
        return ans;
    }
};