
class Solution {
public:
    string reformatNumber(string number) {
        string ans = "";
        for(char c : number){
            if(isdigit(c)){
                ans += c;
            }
        }
        auto ret = reformat(ans);
        ans = "";
        for(int i = 0; i < ret.size(); i++){
            if(i != 0){
                ans += "-";
            }
            ans += ret[i];
        }
        return ans;
    }
private:
    vector<string> reformat(string s){
        if(s.size() <= 3){
            return {s};
        }
        if(s.size() == 4){
            return {s.substr(0,2), s.substr(2,2)};
        }
        vector<string> ret;
        ret.push_back(s.substr(0,3));
        auto r = reformat(s.substr(3));
        for(auto t : r){
            ret.push_back(t);
        }
        return ret;
    }
};