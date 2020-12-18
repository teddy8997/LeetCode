class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> ABsum = new HashMap<>();
        for(int a : A){
            for(int b : B){
                 if(ABsum.containsKey(a+b))
                    ABsum.put(a+b, ABsum.get(a+b) + 1);
                else
                    ABsum.put(a+b, 1);
            }
        }
        int ans = 0;
        for(int c : C){
            for(int d : D){
                if(ABsum.containsKey(- c - d)){
                    ans += ABsum.get(- c - d);
                }
            }
        }
        return ans;
    }
}