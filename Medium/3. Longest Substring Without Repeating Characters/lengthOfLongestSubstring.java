class Solution {
    public int lengthOfLongestSubstring(String s) {
        int [] lastidx = new int[128];
        Arrays.fill(lastidx, -1);
        int start = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(lastidx[s.charAt(i)] != -1){
                start = Math.max(start, lastidx[s.charAt(i)] + 1);
            }
            lastidx[s.charAt(i)] = i;
            ans = Math.max(ans, i - start + 1);
        }
        return ans;
    }
}