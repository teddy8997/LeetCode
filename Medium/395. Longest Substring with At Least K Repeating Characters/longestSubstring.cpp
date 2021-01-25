class Solution {
public:
    int longestSubstring(string s, int k) {
        return slice(s, 0, s.size(), k);
    }
private:
    int slice(const string &s, int start, int end, int k){
        if(end - start < 1){
            return 0;
        }
        vector<int> m(26, 0);
        for(int i = start; i < end; i++){
            m[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(m[i] && m[i] < k){
                for(int j = start; j < end; j++){
                    if(s[j] == i + 'a'){
                        return max(slice(s, start, j, k),slice(s, j+1, end, k));
                    }
                }
            }
        }
        return end - start;
    }
};