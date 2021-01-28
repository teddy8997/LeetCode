class Solution {
    public int missingNumber(int[] nums) {
        //XOR
        int ans = 0;
        int n = nums.length;
        for(int i = 0; i <= n; i++){
            ans = ans ^ i;
        }
        for(int i = 0; i < n; i++){
            ans = ans ^= nums[i];
        }
        return ans;
    }
}