class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(to_string(nums[i]).size() % 2 == 0){ //直接轉成string看大小就知道他有幾個位
                count++;
            }
        }
        return count;
    }
};