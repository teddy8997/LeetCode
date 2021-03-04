/*
    time complxity: O(n)
    space complexity: O(n)
*/
class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            m.put(nums[i], m.getOrDefault(nums[i], 0) + 1);
        }
        for(int i = 0; i < nums.length; i++){
            if(m.get(nums[i]) > nums.length / 2){
                return nums[i];
            }
        }
        return 0;
    }
}