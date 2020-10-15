class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        //利用兩個指針i以及j, i負責遍歷字串t,j負責遍歷字串s,若找到字串s中的字母與字串t中的字母相同則j指針指向下一個在s字串中的字母繼續比對
        for(int i = 0; i < t.size(); i++){ 
            if(t[i] == s[j] && j < s.size()){
                j++;
            }
        }
        return j == s.size();//若全部都有比對成功j會等於字串s的長度
    }
};