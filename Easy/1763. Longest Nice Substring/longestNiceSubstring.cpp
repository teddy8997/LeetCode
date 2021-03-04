/*
    把function移除直接在main中判斷降低時間複雜度
    time complexity: O(n^2 * 26)
    space complextiy: O(1)
*/
class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            vector<int> up(26);
            vector<int> low(26);
            for(int j = i; j < s.size(); j++){
                char c = s[j];
                if(isupper(c)){
                    up[c - 'A'] = 1;
                }else{
                    low[c - 'a'] = 1;
                }
                if(up == low && j - i + 1 > ans.size()){
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};