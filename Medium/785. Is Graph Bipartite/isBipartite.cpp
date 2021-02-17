/*
    參考:https://zxi.mytechroad.com/blog/graph/leetcode-785-is-graph-bipartite/
    將每個node塗色，沒訪問過為0，當前node為1，當前node的鄰居為-1
    如果有衝突就代表不能分返回false
*/
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n);
        for(int i = 0; i < n; i++){
            if(colors[i] == 0 && !dfs(graph, colors, 1, i)){
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int> &colors, int color, int node){
        if(colors[node]){
            return colors[node] == color;
        }
        colors[node] = color;
        for(int nxt : graph[node]){
            if(!dfs(graph, colors, -color, nxt)){
                return false;
            }
        }
        return true;
    }
};