class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()){
            return 0;
        }
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            findPad(s, i, i, ans);
            findPad(s, i, i + 1, ans);
        }
        return ans;
    }
private:
    void findPad(string s, int i, int j, int &ans){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
            ans++;
        }
    }
};