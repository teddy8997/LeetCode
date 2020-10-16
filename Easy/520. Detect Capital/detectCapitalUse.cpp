class Solution {
public:
    bool detectCapitalUse(string word) {
        //利用一個變數countC來記錄字串word中出現大寫的字數
        int countC = 0;
        for(char c : word){
            if(isupper(c)){
                countC++;
            }
        }
        //如果只出現一次大寫而且這個大寫是出現在第一個字元就返回true
        if(countC == 1 && isupper(word[0])){
            return true;
        }
        //代表全部都小寫
        if(countC == 0){
            return true;
        }
        //代表全部都大寫
        if(countC == word.size()){
            return true;
        }
        return false;
    }
};