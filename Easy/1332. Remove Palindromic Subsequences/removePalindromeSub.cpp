/*
	如果本身就是空字串時就不用進行移除所以回傳0
	如果本身就是一個回文字串就直接移除回傳1
	其他的話 由於題目說字串都是由a和b構成的
	所以我們可以一次先全部移除a 這樣也是一種回文
	再一次全部移除b 所以回傳2
	Time complexity: O(n)
	Space complexity: O(n) / O(1)
*/
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()){
            return 0;
        }
        if(s == string(s.rbegin(), s.rend())){
            return 1;
        }
        return 2;
    }
};