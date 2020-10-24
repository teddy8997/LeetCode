class Solution {
    public boolean isPalindrome(String s) {
        int i = 0; 
        int j = s.length()-1;
        while(i < j){
            if(Character.isLetterOrDigit(s.charAt(i)) == false){
                i++;
            }else if(Character.isLetterOrDigit(s.charAt(j)) == false){
                j--;
            }else if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
}