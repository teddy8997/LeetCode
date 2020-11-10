/*
	
	time complexity: O(n*log(n))
	space complexity: O(1)
*/
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return min( min(nums[n-1] - nums[3], nums[n-2] - nums[2]),
                    min(nums[n-3] - nums[1], nums[n-4] - nums[0]));
    }
};