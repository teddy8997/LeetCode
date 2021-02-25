
class Solution {
    int start, offset;    
    public String longestPalindrome(String s) {
        String ans = "";
        for(int i = 0; i < s.length(); i++){
            pal(s, i, i); //找到以s[i]為中心的回文串
            pal(s, i, i+1); //找到以s[i]為中心的回文串
        }
        return s.substring(start, start + offset);
    }
    private void pal(String s, int l, int r){
        while(l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)){
            l--;
            r++;
        }
        if(offset < r - l - 1){ //如果前一次儲存的位移小於現在的位移值(也就是找到比較長的回文串)，就更新值
            start = l + 1;
            offset = r - l - 1;
        }
    }
}