/*
    1,2,3 -> 3,2,1
    3,2,1 -> 1,2,3
    1,1,5 -> 1,5,1
    如果題目給的數列已經是降序排列的話就代表他 是全排列的最後一種情形，直接將數列反轉就是答案
    例如1 2 7 4 3 1
    下一個排列為 1 3 1 2 4 7
    我們可以觀察發現如果從最後一位往前看數字逐漸變大到了2才減小，然後再從最後往前找第一個比2大的數字3後 swap
    交換後再將3後面的數反轉就好
    time complexity: O(n) 
    space complexity: O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        for(i = nums.size() - 2; i >= 0; i--){
            if(nums[i+1] > nums[i]){ // 找出i = ?時數字開始減小
                for(j = nums.size()-1; j > i; j--){
                    if(nums[j] > nums[i]){ //由後往前找出第一個比nums[i]大的數
                        break;
                    }
                }
                swap(nums[i], nums[j]); //找到後swap
                reverse(nums.begin() + i + 1, nums.end()); //反轉剛剛交換的數之後的數字
                return;
            }
        }
        reverse(nums.begin(), nums.end()); //如果是降序就直接反轉數列
    }
};