class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visit(numCourses, 0);
        for(auto p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(dfs(i, graph, visit, ans)){
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    bool dfs(int cur, vector<vector<int>> &graph, vector<int> &visit, vector<int> &ans){
        if(visit[cur] == 1){
            return true;
        }
        if(visit[cur] == 2){
            return false;
        }
        visit[cur] = 1;
        
        for(auto g : graph[cur]){
            if(dfs(g, graph, visit, ans)){
                return true;
            }
        }
        visit[cur] = 2;
        ans.push_back(cur);
        return false;
    }
};
