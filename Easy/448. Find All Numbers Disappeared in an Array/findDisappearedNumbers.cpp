class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
            想法是對於每一個數字nums[i],如果對應的nums[nums[i] - 1]是正數我們就變負數
            如果已經是負數代表是重複出現的數字就不變了，最後剩下沒變成負數的index + 1就是消失的數
            time complexity: O(n)
            space complexity: O(1)
        */
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]) - 1;
            nums[index] = (nums[index] > 0) ? -nums[index] : nums[index]; 
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};