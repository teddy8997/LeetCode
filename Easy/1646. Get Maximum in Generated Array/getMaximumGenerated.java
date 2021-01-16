class Solution {
    public int getMaximumGenerated(int n) {
        int [] nums = new int [n+1];
        nums[0] = 0;
        if(n > 0){
            nums[1] = 1;
        }
        for(int i = 1; i * 2 <= n; i++){
            nums[2 * i] = nums[i];
            if(2 * i + 1 <= n){
                nums[2 * i + 1] = nums[i] + nums[i + 1];
            }
        }
        int ans = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++){
            ans = Math.max(ans, nums[i]);
        }
        return ans;
    }
}