class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> str = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> res;
        //將每個word轉成摩斯密碼，再利用set來去重複，最後set裡面元素的各數就是答案
        for(int i = 0; i < words.size(); i++){
            string s = "";
            for(int j = 0; j < words[i].size(); j++){
                s += str[words[i][j] - 'a'];
            }
            res.insert(s);
        }
        return res.size();
    }
};