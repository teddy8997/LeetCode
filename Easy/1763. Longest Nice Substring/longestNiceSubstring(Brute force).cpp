/*
    參考:https://zxi.mytechroad.com/blog/string/leetcode-1763-longest-nice-substring/
    使用暴力法並使用一個函式來判斷大小寫是否相等
    值得注意的是利用當前的子字符串跟存在答案中的子字符串長度做比較可以排除先後順序
    time complexity: O(n^3)
    space complexity: O(1)

*/
class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans;
        for(int i = 0; i < s.size(); i++){
            for(int j = i+1; j < s.size(); j++){
                string ss = s.substr(i, j - i + 1);
                if(isNice(ss) && ss.size() > ans.size()){
                    ans = ss;
                }
            }
        }
        return ans;
    }
private:
    bool isNice(string s){
        vector<int> up(26);
        vector<int> low(26);
        for(char c : s){
            if(isupper(c)){
                up[c - 'A'] = 1;
            }else{
                low[c - 'a'] = 1;
            }
        }
        return up == low;
    }
};