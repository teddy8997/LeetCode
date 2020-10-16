class Solution {
    public int maxDepth(String s) {
        int ans = 0;
        int d = 0;
        for(char c : s.toCharArray()){
            if(c == '('){
                d++;
                ans = Math.max(ans, d);
            }else if(c == ')'){
                d--;
            }
        }
        return ans;
    }
}