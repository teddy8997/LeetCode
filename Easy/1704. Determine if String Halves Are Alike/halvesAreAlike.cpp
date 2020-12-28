/*
    利用將母音大小寫放進set中，在把字串前半及後半一個一個檢查有沒有在set中
    有的話就加一，最後檢查兩個字串母音出現次數有無相等
*/
class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        int n = s.size();
        int S1CountV = 0;
        int S2CountV = 0;
        for(int i = 0; i < n / 2; i++){
            if(st.count(s[i])){
                S1CountV++;
            }
        }
        for(int i = n / 2 ; i < n; i++){
            if(st.count(s[i])){
                S2CountV++;
            }
        }
        return S1CountV == S2CountV;
    }
};