class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int i = 0;
        int j = 0;
        for(i = 0; i < haystack.size(); i++){
            for(j = 0; j < needle.size(); j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(needle.size() == j){
                return i;
            }
        }
        return -1;
    }
};