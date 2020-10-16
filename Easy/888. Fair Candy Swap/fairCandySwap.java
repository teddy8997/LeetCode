class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sumA = 0;
        int sumB = 0;
        int diff = 0;
        for(int i = 0; i < A.length; i++){
            sumA += A[i];
        }
        for(int i = 0; i < B.length; i++){
            sumB += B[i];
        }
        diff = (sumA - sumB) /2;
        Set <Integer> s = new HashSet();
         for(int i = 0; i < A.length; i++){
            s.add(A[i]);
        }
         for(int i = 0; i < B.length; i++){
            if(s.contains(B[i]+ diff)){
                return new int[] {B[i]+ diff, B[i]};
            }
        }
        return new int [] {,};
    }
}