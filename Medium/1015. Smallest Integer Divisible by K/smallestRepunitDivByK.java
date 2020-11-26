class Solution {
    public int smallestRepunitDivByK(int K) {
        int n = 0;
        for(int i = 0; i < K; i++){
            n = (n * 10 + 1) % K;
            if(n == 0){
                return i+1;
            }
        }
        return -1;
    }
}