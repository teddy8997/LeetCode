class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                continue;
            }else {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++;
            }
        }
    }
}