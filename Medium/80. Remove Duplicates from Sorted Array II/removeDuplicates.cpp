/*
    因為是有序的數列所以我們把i紀錄第一位不滿足條件的位子
    j 則是便利整個數列
    如果nums[j] != nums[i-2]的時候就把nums[i] = nums[j]
    然後i++
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int i = 0;
        for(int n : nums){
            if(i < 2 || n != nums[i-2]){
                nums[i] = n;
                i++;
            }
        }
        return i;
    }
};