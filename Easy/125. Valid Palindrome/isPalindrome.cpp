class Solution {
public:
    bool isPalindrome(string s) {
        /*
            使用兩個指標i,j分別從頭尾開始遍歷，
            如果頭或尾遇到的不是數字或是英文字母的話就分別往右移(i++)或往左移(j--)
            若在s[i]和s[j]這兩個都是英文字母或是數字但是兩個並不相等就可以確定他不是回文
            剩下的情況就是都是數字或英文字母而且s[i]和s[j]相等的情形我們就把i往右移j往左移
        */
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            if(!isalnum(s[i])){
                i++;
            }else if(!isalnum(s[j])){
                j--;
            }else if(tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};