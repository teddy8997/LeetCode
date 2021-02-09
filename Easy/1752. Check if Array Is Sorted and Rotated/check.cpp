/*
    time complexity: O(n)
    space complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size() < 3){
            return true;
        }
        int index = 1;
        //找出前半部非降序
        while(index < nums.size() && nums[index] >= nums[index-1]){
            index++;
        }
        if(index == nums.size()){
            return true;
        }
        index++;
        //後半部非降序
        while(index < nums.size() && nums[index] >= nums[index-1]){
            index++;
        }
        //檢查後半部的最大值有沒有大於前半部的最小值
        if(nums.back() > nums[0]){
            return false;
        }
        return index == nums.size();
    }
};