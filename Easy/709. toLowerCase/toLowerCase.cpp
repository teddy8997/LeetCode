class Solution {
public:
    string toLowerCase(string str) {
        string ans = "";
        for(char c : str){
            if(isupper(c)){
                ans += tolower(c);
            }else{
                ans += c;
            }
        }
        return ans;
    }
};