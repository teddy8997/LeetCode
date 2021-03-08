/*
	將數字轉成3進位，只要餘數出現2就代表他不能被表示成3進位 返回false;
*/
class Solution {
public:
    bool checkPowersOfThree(int n) {
       while(n){
           if(n % 3 == 2){
               return false;
           }
           n /= 3;
       }
        return true;
    }
};
