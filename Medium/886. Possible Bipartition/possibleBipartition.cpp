class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        g_ = vector<vector<int>>(N);
        for(auto d : dislikes){
            g_[d[0] - 1].push_back(d[1] - 1);
            g_[d[1] - 1].push_back(d[0] - 1);
        }
        color_ = vector<int>(N, 0);
        for(int i = 0; i < N; i++){
            if(color_[i] == 0 && !dfs(i, 1)){
                return false;
            }
        }
        return true;
    }
private:
    vector<vector<int>> g_;
    vector<int> color_;
    bool dfs(int cur, int col){
        color_[cur] = col;
        for(int nxt : g_[cur]){
            if(color_[nxt] == col){
                return false;
            }
            if(color_[nxt] == 0 && !dfs(nxt, -col)){
                return false;
            }
        }
        return true;
    }
};