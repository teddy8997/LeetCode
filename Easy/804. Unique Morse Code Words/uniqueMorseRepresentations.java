class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String [] s = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Set res = new HashSet();
        for(int i = 0; i < words.length; i++){
            String sol = "";
            for(int j = 0; j < words[i].length(); j++){
                sol += s[words[i].charAt(j) - 'a'];
            }
            res.add(sol);
        }
        return res.size();
    }
}