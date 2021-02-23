class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l = 0;
        int r = 0;
        Map<Character, Integer> window = new HashMap<>();
        int ans = 0;
        while(r < s.length()){
            char c1 = s.charAt(r);
            window.put(c1, window.getOrDefault(c1, 0) + 1);
            r++;
            while(window.get(c1) > 1){
                char c2 = s.charAt(l);
                window.put(c2, window.get(c2) - 1);
                l++;
            }
            ans = Math.max(ans, r - l);
        }
        return ans;
    }
}