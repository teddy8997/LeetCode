class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> pair;
        string ans = "";
        for(auto v : knowledge){
            pair[v[0]] = v[1];
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                string key = "";
                i++;
                while(i < s.size() && s[i] != ')'){
                    key += s[i];
                    i++;
                }
                if(pair.count(key)){
                    ans += pair[key];
                }else{
                    ans += "?";
                }
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};