/*
    題目要求時間複雜度要在logn內，我們可以想到使用binary search
    比較nums[m] 是否大於 nums[m + 1]
    如果是代表最大值在左邊
    如果不是代表最大值在右邊
    
    Time complexity: O(logn)
    Space complexity: O(1)
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] > nums[m + 1]){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};