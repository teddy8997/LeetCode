/*
    這題的關鍵點是要知道'('的下一個出現的是')'或是'a'
    就可以知道ans字串要加入哪個字串進去
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    string interpret(string command) {
        string ans;
        for(int i = 0; i < command.size(); i++){
            if(command[i] == 'G'){
                ans += "G";
            }else if(command[i] == '('){
                if(command[i+1] == ')'){
                    ans += "o";
                }else{
                    ans += "al";
                }
            }
        }
        return ans;
    }
};