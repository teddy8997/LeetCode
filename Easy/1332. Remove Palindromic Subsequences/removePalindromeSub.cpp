/*
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