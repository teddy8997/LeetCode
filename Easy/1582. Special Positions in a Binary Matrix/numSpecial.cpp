/*
    遍歷mat矩陣兩次
    第一次儲存哪行哪列出現1的次數
    第二次如果遇到1就判斷他的那行那個列出現過1的次數是不是等於1
    time complexity: O(n * m)
    space complexity: O(m + n)
*/
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1 && row[i] == 1 && col[j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};