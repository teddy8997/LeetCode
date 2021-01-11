class Solution {
    public int[] decode(int[] encoded, int first) {
        int n = encoded.length+1;
        int [] ans = new int [n];
        Arrays.fill(ans, first);
        for(int i = 0; i < n-1; i++){
            ans[i+1] = encoded[i] ^ ans[i];
        }
        return ans;
    }
}