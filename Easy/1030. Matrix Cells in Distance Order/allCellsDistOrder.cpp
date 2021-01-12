
/*version 1*/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        vector<pair<int, vector<int>>> tmp;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                tmp.push_back({abs(i - r0) + abs(j - c0), {i, j}});
            }
        }
        sort(tmp.begin(), tmp.end(), [](auto a, auto b){
            return a.first < b.first;
        });
        for(auto m : tmp){
            ans.push_back(m.second);
        }
        return ans;
    }
};
/*version 2*/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                ans.push_back({i, j});
            }
        }
        sort(ans.begin(), ans.end(), [r0, c0](auto a, auto b){
            return (abs(a[0] - r0)  + abs(a[1] - c0)) < (abs(b[0] - r0) + abs(b[1] - c0));
        });
        return ans;
    }
};