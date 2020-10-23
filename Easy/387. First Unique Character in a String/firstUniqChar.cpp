class Solution {
public:
    int firstUniqChar(string s) {
        //利用map統計每個字母出現的次數後再遍歷一次找出第一個只出現一次的字母並且回傳她的index
        unordered_map<int, int> m;
        for(char c : s){
            m[c]++;
        }
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};