class Solution {
    public List<String> letterCasePermutation(String S) {
        List<String> ans = new ArrayList<>();
        dfs(S.toCharArray(), 0, ans);
        return ans;
    }
    private void dfs(char [] S, int d, List<String> ans){
        if(d == S.length){
            ans.add(new String(S));
            return;
        }
        dfs(S, d+1, ans);
        if(!Character.isLetter(S[d])){
            return;
        }
        S[d] ^= (1 << 5);
        dfs(S, d+1, ans);
        S[d] ^= (1 << 5);
    }
}