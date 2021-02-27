/*
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> tmp;
        for(int i = 0; i < nums.size(); i++){
            tmp[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(tmp.count(target - nums[i]) && tmp[target - nums[i]] != i){
                return {i, tmp[target - nums[i]]};
            }
        }
        return {-1,-1};
    }
};