/*
    題目可以分割為和dictionary中的每個string和s 找共同子序列
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(string d : dictionary){
            if(isSub(d, s)){
                if(d.size() > ans.size() || (d.size() == ans.size() && d < ans)){
                    ans = d;
                }
            }
        }
        return ans;
    }
private:
    bool isSub(string d, string s){
        int j = 0;
        for(int i = 0; i < s.size() && j < d.size(); i++){
            if(d[j] == s[i]){
                j++;
            }
        }
        return j == d.size();
    }
};