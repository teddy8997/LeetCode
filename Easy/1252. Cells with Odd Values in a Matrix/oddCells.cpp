class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n);
        vector<int> col(m);
        for(auto idx : indices){
            row[idx[0]]++;
            col[idx[1]]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += (row[i] + col[j]) %2;
            }
        }
        return ans;
    }
};