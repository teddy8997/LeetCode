class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        int ans = 0;
        int sum0_i = 0;
        for(int i = 0; i < n; i++){
            sum0_i += nums[i];
            int sum0_j = sum0_i - k;
            if(preSum.count(sum0_j)){
                ans += preSum[sum0_j];
            }
            preSum[sum0_i]++;
        }
        return ans;
    }
};