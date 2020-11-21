/*
    由33. Search in Rotated Sorted Array的方向想
    當nums[m]的數小於最右邊的數nums[r]，可以知道右半邊是有序的
    當nums[m]的數大於最右邊的數nums[r]，可以知道左半邊是有序的
    那如果允許重複值的話會有兩種狀況[3,1,1],[1,1,3,1]對於這兩種中間值等於最右邊的情況來看3可以在左邊或右邊，我們需要處理這部分，所以我們把最右值向左一位就可以繼續循環如果還相同就繼續往左移植到不相同
    time complexity: O(logn)
    space complexity: O(1)
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target){
                return true;
            }
            if(nums[m] < nums[r]){
                if(nums[m] < target && nums[r] >= target){
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }else if(nums[m] > nums[r]){
                    if(nums[l] <= target && nums[m] > target){
                        r = m - 1;
                    }else{
                        l = m + 1;
                    }
            }else{
                r--;        
            }
        }
        return false;
    }
};