class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        //利用兩個指針i,j來記錄，若遇到0 i向右移
        //若不是遇到0 和在位置j的值交換，交換後j往右移
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                continue;
            }else{
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++;
            }
        }
    }
};