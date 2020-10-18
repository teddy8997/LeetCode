class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return check(S) == check(T);
    }
private:
    string check(string &s){
        string tmp = "";
        for(char c : s){
            if(c == '#'){
                if(!tmp.empty()){
                    tmp.pop_back();
                }
            }else{
                tmp.push_back(c);
            }
        }
        return tmp;
    }
};