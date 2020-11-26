class Solution {
    public int removePalindromeSub(String s) {
        if(s.length() == 0){
            return 0;
        }
        String s2 = "";
        for(int i = s.length()-1; i >= 0; i--){
            s2 += s.charAt(i);
        }
        if(s.equals(s2)){
            return 1;
        }
        return 2;
    }
}