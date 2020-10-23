class Solution {
    public int firstUniqChar(String s) {
        //題目說只會出現小寫所以用一個陣列存26個字母分別出現的次數
        //再重新遍歷找出第一個出現一次的字母 並回傳她的index
        //time complexity: O(n)
        //Space : O(1)
        int [] a = new int [26];
        for(char c : s.toCharArray()){
            a[c - 'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(a[s.charAt(i) - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
}