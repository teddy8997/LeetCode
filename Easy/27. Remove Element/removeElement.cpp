class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
            利用變數index來記錄目前和val不一樣的值填到的位置
            如果nums[i]的值和val不相等我們就把nums[i]的值填到nums[index]
            然後index++
            time complexity: O(n)
            space complexity: O(1)
        */
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};