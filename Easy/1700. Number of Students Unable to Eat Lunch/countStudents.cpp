/*
    依據題意模擬步驟就可以解出來，比較特別的是使用一個變數c來紀錄重複次數，如果配對到的話就將重複次數歸0
    一直配對不到直到超過還沒吃到的人數就代表已經沒有解了，跳出迴圈
    time complexity: O(n^2)
    space complexity: O(n)
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int s : students){
            q.push(s);
        }
        int c = 0;
        int i = 0;
        while(!q.empty()){
            int s = q.front();
            q.pop();
            if(s == sandwiches[i]){
                i++;
                c = 0;
            }else{
                q.push(s);
            }
            if(++c > q.size()){
                break;
            }
        }
        return q.size();
    }
};