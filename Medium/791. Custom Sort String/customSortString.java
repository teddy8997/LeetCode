class Solution {
    public String customSortString(String S, String T) {
        int [] count =new int [26];
        for(char c: T.toCharArray()){
            count[ c - 'a']++;
        }
        StringBuffer b = new StringBuffer();
        for(char c: S.toCharArray()){
            for(int i = 0; i < count[c - 'a']; i++){
                b.append(c);
            }
            count[c - 'a'] = 0;
        }
        for(char c : T.toCharArray()){
            if(count[c - 'a'] != 0){
                for(int j = 0; j < count[c - 'a']; j++){
                    b.append(c);
                }
                count[c - 'a'] = 0;
            }
        }
        return b.toString();
    }
}