class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string> dead (deadends.begin(), deadends.end());
        if(dead.count(start)){
            return -1;
        }
        if(start == target){
            return 0;
        }
        queue<string> q;
        q.push(start);
        unordered_set<string> visited;
        visited.insert(start);
        int cnt = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string cur = q.front();
                q.pop();
                if(cur == target){
                    return cnt;
                }
                if(dead.count(cur)){
                    continue;
                }
                for(int j = 0; j < 4; j++){
                    string up = plusOne(cur, j);
                    if(!visited.count(up)){
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if(!visited.count(down)){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
private:
    string plusOne(string cur, int i){
        if(cur[i] == '9'){
            cur[i] = '0';
        }else{
            cur[i]++;
        }
        return cur;
    }
     string minusOne(string cur, int i){
        if(cur[i] == '0'){
            cur[i] = '9';
        }else{
            cur[i]--;
        }
        return cur;
    }
};