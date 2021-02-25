class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        unordered_map<char, char> m{{')', '('}, {']', '['}, {'}','{'}};
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                left.push(c);
            }else{
                if(!left.empty() && m[c] == left.top()){
                    left.pop();
                }else{
                    return false;
                }
            }
        }
        return left.empty();
    }
};