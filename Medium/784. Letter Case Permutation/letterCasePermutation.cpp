/*
參考:https://zxi.mytechroad.com/blog/searching/leetcode-784-letter-case-permutation/
*/
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(S, 0, ans);
        return ans;
    }
private:
    void dfs(string &S, int d, vector<string> &ans){
        if(d == S.size()){
            ans.push_back(S);
            return;
        }
        dfs(S, d+1, ans);
        if(!isalpha(S[d])){
            return;
        }
        S[d] ^= (1 << 5);
        dfs(S, d+1, ans);
        S[d] ^= (1 << 5); //記得要將字母復原
    }
};