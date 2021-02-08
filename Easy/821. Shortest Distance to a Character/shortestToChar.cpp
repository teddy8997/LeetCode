class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int p = 0;
        vector<int> ans(s.size(), INT_MAX);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                while(p <= i){
                    ans[p] = i - p;
                    p++;
                }
            }
        }
        int p2 = s.size() - 1;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == c){
                while(p2 >= i){
                    ans[p2] = min(ans[p2], p2 - i);
                    p2--;
                }
            }
        }
        return ans;
    }
};