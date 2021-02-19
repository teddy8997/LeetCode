/*
    參考: https://zxi.mytechroad.com/blog/string/leetcode-1576-replace-all-s-to-avoid-consecutive-repeating-characters/
    主要就是遇到問號時判斷他他的左右邊有沒有和abc一樣
*/
class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] != '?'){
                continue;
            }
            for(char c : "abc"){
                if((i == 0 || s[i - 1] != c) && (i == n-1 || s[i+1] != c)){
                    s[i] = c;
                    break;
                }
            }
        }
        return s;
    }
};