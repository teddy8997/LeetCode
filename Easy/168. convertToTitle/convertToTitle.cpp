/*
    簡單的一個題目
    =比較要注意的是如果直接以n % 26的話 Z會被吃掉
    所以我們先把n-- 再 % 26這樣就可以把0-25 對應到A - Z
*/
class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 0){
            return "";
        }
        string ans = "";
        while(n){
            n--;
            ans = (char)(n % 26 + 'A') + ans;
            n = n / 26;
        }
        return ans;
    }
};