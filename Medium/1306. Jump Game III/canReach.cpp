/*
    因為每一個點都可以走index + arr[index]或是index - arr[index]
    所以我們可以把樹組中的每一個數字看為一個節點，該節點能夠連接的下一層節點可以是index + arr[index]或是index - arr[index]
    如果下一個節點沒有越界我們就可以往下走直到找到當前的值為0，找到後返回true
    如果所有路線走完都沒有找到值為0的節點則返回flase
    那二元樹找特定值的問題最值觀的方法就是使用BFS來解
*/
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<bool> visited(arr.size(),0);
        visited[start] = true;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            if(arr[index] == 0){
                return true;
            }
            int next1 = index - arr[index];
            if(next1 >= 0 && !visited[next1]){
                q.push(next1);
                visited[next1] = true;
            }
            int next2 = index + arr[index];
            if(next2 < arr.size() && !visited[next2]){
                q.push(next2);
                visited[next2] = true;
            }
        }
        return false;
    }
};