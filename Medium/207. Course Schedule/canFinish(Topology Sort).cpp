class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < numCourses; i++){
            inDegree[i] = 0;
            graph[i] = {};
        }
        for(int i = 0; i < prerequisites.size(); i++){
            int prereq = prerequisites[i][1];
            int course = prerequisites[i][0];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }
        queue<int> source;
        for(auto p : inDegree){
            if(p.second == 0){
                source.push(p.first);
            }
        }
        vector<int> sortedC;
        while(!source.empty()){
            int course = source.front();
            source.pop();
            sortedC.push_back(course);
            for(auto child : graph[course]){
                if(--inDegree[child] == 0){
                    source.push(child);
                }
            }
        }
        return sortedC.size() == numCourses;
    }
};