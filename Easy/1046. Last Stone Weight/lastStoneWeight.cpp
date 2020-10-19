class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int n : stones){
            q.push(n);
        }
        while(q.size() >= 2){
            int y = q.top();
            q.pop();
            int x = q.top();
            if(x == y){
                q.pop();
            }else{
                q.pop();
                q.push(y - x);
            }
        }
        return q.empty()? 0 : q.top(); 
    }
};