/*
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans = "";
        int count = 0;
        int n = S.size();
        for(int i = n - 1; i >= 0; i--){
            char c = S[i];
            if(c == '-'){
                continue;
            }
            if(c >= 'a' && c <= 'z'){
                c = toupper(c);
            }
            ans.push_back(c);
            count++;
            if(count % K == 0){
                ans.push_back('-');
            }
        }
        if(!ans.empty() && ans.back() == '-'){
            ans.pop_back();
        }
        return string(ans.rbegin(), ans.rend());
    }
};
