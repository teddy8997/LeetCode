class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n+1);
        for(int i = 0; i < n; i++){
            preSum[i+1] = preSum[i] + nums[i];
        }
        for(int i = 0; i < n; i++){
            nums[i] = (2 * i + 1 - n) * nums[i] - preSum[i] + preSum[n] - preSum[i+1];
        }
        return nums;
    }
};