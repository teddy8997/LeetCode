/*
    BFS
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(visited[cur]){
                continue;
            }
            visited[cur] = 1;
            for(int n : rooms[cur]){
                q.push(n);
            }
        }
        for(int n : visited){
            if(n == 0){
                return false;
            }
        }
        return true;
    }
};