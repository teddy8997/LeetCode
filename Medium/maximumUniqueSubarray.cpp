/*
    sliding window + hashset
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        int r = 0;
        unordered_set<int> s;
        int ans = 0;
        int sum = 0;
        while(r < nums.size()){
            while(s.count(nums[r]) && l < r){
                sum -= nums[l];
                s.erase(nums[l]);
                l++;
            }
            s.insert(nums[r]);
            sum += nums[r];
            r++;
            ans = max(ans, sum);
        }
        return ans;
    }
};