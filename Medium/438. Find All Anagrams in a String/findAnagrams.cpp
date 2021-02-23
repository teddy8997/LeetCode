class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for(char c : p){
            needs[c]++;
        }
        int match = 0;
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
                if(r - l == p.size()){
                    ans.push_back(l);
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
        return ans;
    }
};