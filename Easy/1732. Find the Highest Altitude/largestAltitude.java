class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int [] ans = new int [n+1];
        ans[0] = 0;
        int i = 1;
        for(int num : gain){
            ans[i] = ans[i - 1] + num;
            i++;
        }
        int max = Integer.MIN_VALUE;
        for(int j = 0; j < ans.length; j++){
            if(ans[j] > max){
                max = ans[j];
            }
        }
        return max;
    }
}