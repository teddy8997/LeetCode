/*
    backtracing
    
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int countArrangement(int n) {
        count = 0;
        vector<bool> visited(n+1,false);
        caculate(n, 1, visited);
        return count;
    }
    int count;
private:
    void caculate(int N, int pos, vector<bool> &visited){
        if(pos > N){
            count++;
        }
        for(int i = 1; i <= N; i++){
            if(!visited[i] && (pos % i == 0 || i % pos == 0)){
                visited[i] = true;
                caculate(N, pos + 1, visited);
                visited[i] = false;
            }
        }
    }
};