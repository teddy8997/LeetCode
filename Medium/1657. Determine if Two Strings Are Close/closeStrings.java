class Solution {
    public boolean closeStrings(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 != len2){
            return false;
        }
        int [] f1 = new int [26];
        int [] f2 = new int [26];
        int [] s1 = new int [26];
        int [] s2 = new int [26];
        for(char c : word1.toCharArray()){
            f1[c - 'a']++;
            s1[c - 'a'] = 1;
        }
        for(char c : word2.toCharArray()){
            f2[c - 'a']++;
            s2[c - 'a'] = 1;
        }
        Arrays.sort(f1);
        Arrays.sort(f2);
        return Arrays.equals(f1,f2) && Arrays.equals(s1,s2);
    }
}