class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for(vector<string> it : items){
            if(ruleKey == "type"){
                if(ruleValue == it[0]){
                    ans++;
                }
            }
            if(ruleKey == "color"){
                if(ruleValue == it[1]){
                    ans++;
                }
            }
            if(ruleKey == "name"){
                if(ruleValue == it[2]){
                    ans++;
                }
            }
        }
        return ans;
    }
};