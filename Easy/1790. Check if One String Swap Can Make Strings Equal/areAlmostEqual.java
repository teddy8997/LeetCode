class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1.equals(s2)){
            return true;
        }
        HashSet<Character> hs = new HashSet<>();
        for(char c : s1.toCharArray()){
            hs.add(c);
        }
        int count = 0;
        for(int i = 0; i < s1.length(); i++){
            if(hs.contains(s2.charAt(i)) && s1.charAt(i) != s2.charAt(i)){
                count++;
            }
        }
        return count == 2? true : false;
    }
}