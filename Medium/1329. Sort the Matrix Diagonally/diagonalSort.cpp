/*
    有兩點a(x1, y1), b(x2, y2)，如果兩個點在同一線上的話x1 - y1 = x2 - y2
    我們利用這點用一個MAP儲存i - j當KEY，將在同一線上的值都存起來
    再將每一組同一線上的值由小到大排序
    最後再把值存回去新的一個二為數組
    time complexity: O(m*n)
    space complexit: O(m*n)
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if(n == 0 || m == 0){
            return {};
        }
        unordered_map<int, deque<int>> dia;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dia[i - j].push_back(mat[i][j]);
            }
        }
        for(auto &[key, val] : dia){
            sort(val.begin(), val.end());
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                auto &v = dia[i-j];
                ans[i][j] = v.front();
                v.pop_front();
            }
        }
        return ans;
    }
};