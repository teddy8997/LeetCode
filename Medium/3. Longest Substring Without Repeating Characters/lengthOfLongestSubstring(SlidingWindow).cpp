class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        int start = 0;
        int end = 0;
        set<char> st;
        while(end < n){
            if(st.find(s[end]) == st.end()){
                st.insert(s[end]);
                maxLen = max(maxLen, end - start + 1);
                end++;
            }else{
                st.erase(st.find(s[start]));
                start++;
            }
        }
        return maxLen;
    }
};