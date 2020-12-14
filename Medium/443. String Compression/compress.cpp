/*
    使用雙指針i,j,使用j來找重複的字符串的個數，使用while迴圈最後j指向的是第一個和i指向字符不同的地方
    此時我們需要先將字符寫進chars中，然後注意要判斷j是不是和i差1
    因為如果個數只有1個後面不需要加個數所以需要直接跳過
    如果不是差1的話 我們就將j - i的差轉成字符串一位一位加上去chars
    
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cur = 0;
        for(int i = 0, j = 0; i < n; i = j){
            while(j < n && chars[j] == chars[i]){
                j++;
            }
            chars[cur++] = chars[i];
            if(j - i == 1){
               continue; 
            }
            for(char c : to_string(j - i)){
                chars[cur++] = c;
            }
        }
        return cur;
    }
};