/*
    time complexity: O(n^2)
    space complexity: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size()-1; i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] == target - nums[i]){
                    return {i, j};
                }
            }
        }
        return {-1,-1};
    }
};