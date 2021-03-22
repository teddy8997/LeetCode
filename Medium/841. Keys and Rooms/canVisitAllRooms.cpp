/*
    dfs
*/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n);
        dfs(rooms, visited, 0);
        for(int v : visited){
            if(!v){
                return false;
            }
        }
        return true;
    }
private:
    void dfs(vector<vector<int>> &rooms, vector<int> &visited, int d){
        visited[d] = 1;
        for(int n : rooms[d]){
            if(!visited[n]){
                dfs(rooms, visited, n);
            }
        }
    }
};