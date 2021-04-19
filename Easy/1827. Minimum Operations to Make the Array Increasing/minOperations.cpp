/*
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= last) {
                count += last - nums[i] + 1;
                nums[i] = last + 1;
            }
            last = nums[i];
        }
        return count;
    }
};