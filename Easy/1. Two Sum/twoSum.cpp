class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
            建立一個map來記錄每一個數字以及他的index，
            然後再遍歷一次每個數字並且檢查target減去目前數字是否存在map中
            需要注意的一點是查找出來的index不能等於當前數的index
        */
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            if(m.count(target - nums[i]) && i != m[target - nums[i]]){
                return {i, m[target - nums[i]]};
            }
        }
        return {};
    }
};