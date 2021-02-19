/*
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int ans = 0;
        int cur = 0;
        for(int i = 2; i < A.length; i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                ans += (++cur);
            }else{
                cur = 0;
            }
        }
        return ans;
    }
}