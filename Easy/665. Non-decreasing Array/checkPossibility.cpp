/*
    4, 2, 3 => 2, 2, 3
    -1, 4, 2, 3 => -1, 2, 2, 3
    2, 3, 3, 2, 4 => 2, 3, 3, 3, 4
    觀察以上例子發現nums[i] < nums[i-1]時，例1的話4前面沒有數字所以我們直接修改nums[i-1] = nums[i]
    例2的話4前面有數字 nums[i - 2] < nums[i] 我們直接修改nums[i-2] = nums[i]
    例3的話如果nums[i-2] > nums[i] 的話 我們直接修改nums[i] = nums[i-1]
    而最多只能修改一次所以我們使用一個count來檢查還有沒有修改的次數
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]){
                if(count == 0){
                    return false;
                }
                if(i == 1 || nums[i] >= nums[i - 2]){
                    nums[i - 1] = nums[i]; 
                }else{
                    nums[i] = nums[i - 1];
                }
                count--;     
            }
        }
        return true;
    }
};