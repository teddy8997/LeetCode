/*
	time complexity: O(nlogn)
	space complexity: O(1)
*/
class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }
}