class Solution {
public:
    bool checkValidString(string s) { 
        /*
        不合理的匹配有兩種CASE
        1. 右括號太多，沒有足夠的左括號或者是星號匹配
        2. 左括號太多，沒有足夠的右括號或者是星號匹配
        */
        //Time complexity:O(n)
        int leftWild = 0;
        int left = 0;
        for(char c : s){
            //確定右括號都有匹配
            if(c == ')'){
                if(leftWild == 0){ //代表左括號太少了(也就是右括號太多)
                    return false;
                }
                leftWild--;
            }else{
                leftWild++;
            }
            //確定全部的左括號都有匹配
            if(c == '('){
                left++;
            }else{
                left = max(0, left - 1);
            }
        }
        return left == 0;
    }
};