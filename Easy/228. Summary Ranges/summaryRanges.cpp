class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        int n = nums.size();
        /*
            i紀錄連續序列起點
            j紀錄連續數列的長度
            只要每一次檢查下一個數是不是遞增如果是就繼續遍歷
            如果不是就要判斷j是不是為1 如果是代表他是一個數
            如果不是代表他是序列
        */
        while(i < n){
            int j = 1;
            while(i + j < n && (long)nums[i + j] - nums[i] == j){
                j++;
            }
            ans.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            i += j;
        }
        return ans;
    }
};