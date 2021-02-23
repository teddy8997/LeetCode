class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        int l = 0;
        int r = 0;
        int match = 0;
        int minLen = INT_MAX;
        int start = 0;
        
        for(char c : t){
            needs[c]++;
        }
        
        while(r < s.size()){
            char c1 = s[r];
            if(needs.count(c1)){
                window[c1]++;
                if(window[c1] == needs[c1]){
                    match++;
                }
            }
            r++;
            
            while(match == needs.size()){
                if(r - l < minLen){
                    start = l;
                    minLen = r - l;
                }
                char c2 = s[l];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2] < needs[c2]){
                        match--;
                    }
                }
                l++;
            }
        }
        return minLen == INT_MAX? "" : s.substr(start, minLen);
    }
};