/*
    這題可以參考: https://zxi.mytechroad.com/blog/graph/leetcode-207-course-schedule/
    主要想法就是先建立起拓樸後，再去檢查有沒有環
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        for(auto p : prerequisites){
            graph[p[0]].push_back(p[1]);
        }
        vector<int> visit(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            if(dfs(i, visit)){
                return false;
            }
        }
        return true;
    }
private:
    vector<vector<int>>graph;
    bool dfs(int cur, vector<int> &visit){
        if(visit[cur] == 1){
            return true;
        }
        if(visit[cur] == 2){
            return false;
        }
        visit[cur] = 1;
        for(auto g : graph[cur]){
            if(dfs(g, visit)){
                return true;
            }
        }
        visit[cur] = 2;
        return false;
    }
};