class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        /*
            因為i < j < k && nums[i] < nums[k] < nums[j]
            所以我們先固定一個變數minN來儲最小值也就是i的位置後
            去找j有沒有小於minN有的話就更新minN的值
            若沒有代表找到nums[i] < nums[j]了
            接下來就從數組尾端開始找到j+1 也就是找k 
            看有沒有小於nums[j]的值有的話就是答案
        */
        int n = nums.size();
        int minN = INT_MAX;
        for(int j = 0; j < n; j++){
            minN = min(minN, nums[j]);
            for(int k = n-1; k > j; k--){
                if(minN < nums[k] && nums[j] > nums[k]){
                    return true;
                }
            }
        }
        return false;
    }
};