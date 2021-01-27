class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); i++){
            int prereq = prerequisites[i][1];
            int course = prerequisites[i][0];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }
        queue<int> q;
        for(int i = 0; i < inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(auto child :graph[course]){
                if(--inDegree[child] == 0){
                    q.push(child);
                }
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }else{
            return vector<int>();
        }
    }
};