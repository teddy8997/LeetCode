class Solution {
    public int maxPower(String s) {
        int count = 0;
        int maxCount = 0;
        char pre = ' ';
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c == pre){
                count++;
            }else{
                count = 1;
                pre = c;
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }
}