/*
    由題目限制可知allowed所出現的數字不會重複而且範圍是1 <= allowed.length <= 26代表只會出現小寫且是英文字母
    我們先用一個大小為26的vector來記錄allowed中字母的出現次數
    接下來在一個一個比對words中各個字串中的字母有沒有出現在vector中有的話就繼續檢查下一位
    沒有的話就break並且把答案減去1
    time complexity: O(n^2)
    space complexity: O(26)
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> allow(26,0);
        for(char c : allowed){
            allow[c - 'a']++;
        }
        int ans = 0;
        for(string s : words){
            for(char c : s){
                if(allow[c - 'a'] == 1){
                    continue;
                }else{
                    ans--;
                    break;
                }
            }
            ans++;
            
        }
        return ans;
    }
};