/*
    這題就照著題目把產生的矩陣列出來然後找出其中最大值就好
    Time complexity: O(n)
    Space complexity: O(n)
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums(n+1);
        nums[0] = 0;
        if(n > 0){
            nums[1] = 1;
        }
        for(int i = 1; i * 2 <= n ; i++){
            nums[2 * i] = nums[i];
            if(2 * i + 1 <= n){
                nums[2 * i + 1] = nums[i] + nums[i + 1];
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};