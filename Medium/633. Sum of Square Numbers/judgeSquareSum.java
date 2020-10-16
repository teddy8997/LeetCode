class Solution {
    public boolean judgeSquareSum(int c) {
        for(int i = (int)Math.sqrt(c); i >= 0; i--){
            if(i * i == c){
                return true;
            }
            int d = c - i * i;
            int sd =(int)Math.sqrt(d);
            if(sd * sd == d){
                return true;
            }
        }
        return false;
    }
}