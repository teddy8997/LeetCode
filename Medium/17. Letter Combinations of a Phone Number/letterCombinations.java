class Solution {
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0){
            return new ArrayList<>();
        }
        String [] dict = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        List<String> ans = new ArrayList<>();
        dfs(digits.toCharArray(), dict, ans, "");
        return ans;
    }
    private void dfs(char [] digits, String[] m, List<String> ans, String s){
        if(s.length() == digits.length){
            ans.add(s);
            return;
        }
        int i = s.length();
        int d = digits[i] - '0';
        for(char letter : m[d].toCharArray()){
            dfs(digits, m, ans, s + Character.toString(letter));
        }
    }
}