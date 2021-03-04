class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sumAll = 0;
        for(int i = 0;i <= nums.size(); i++){
            sumAll += i;
        }
        for(int n : nums){
            sumAll -= n;
        }
        return sumAll;
    }
};