class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //如果vector裡面沒有數字直接回傳0
        if(nums.empty()){
            return 0;
        }
        //使用i, j兩個指針, i指針負責記錄目前不重複的位置
        //j指針就一直遍歷下去當遇到和i那個位子不同的數字
        //i就移到下一個位子和j交換不重複的數字
        //最後不重複的個數就是i+1
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};