class Solution {
    public boolean canJump(int[] nums) {
        int maxPosi = 0;
        for(int i = 0; i < nums.length; i++){
            if(i > maxPosi){
                return false;
            }
            maxPosi = Math.max(i + nums[i], maxPosi);
        }
        return true;
    }
}