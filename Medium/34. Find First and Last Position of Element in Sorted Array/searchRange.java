class Solution {
    int [] ans;
    public int[] searchRange(int[] nums, int target) {
        ans = new int [2];
        getLeft(nums, target);
        getright(nums, target);
        return ans;
    }
    private void getLeft (int [] nums, int target) {
        int len = nums.length;
        int left = 0;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] ==  target) {
                right = mid - 1;
            }else if (nums[mid] < target) {
                left = mid + 1;
            }else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        if (left >= len || nums[left] != target) {
            ans[0] = -1;
        }else {
            ans[0] = left;
        }
    }
    
    private void getright (int [] nums, int target) {
        int len = nums.length;
        int left = 0;
        int right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] ==  target) {
                left = mid + 1;
            }else if (nums[mid] < target) {
                left = mid + 1;
            }else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        if (right < 0 || nums[right] != target) {
            ans[1] = -1;
        }else {
            ans[1] = right;
        }
    }
}