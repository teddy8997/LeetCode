/*
	2的指數轉乘2進位的話就只會有一個1
	所以我們利用n & (n - 1)去除最後一個1 如果結果為0的話就是2的指數
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};