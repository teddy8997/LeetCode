/*
    [sliding window]
    我們可以反向思考，找出總和為整個數組的和減去x的最長子串長度，然後總長度減去找出的子串長度就是題目所求

*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0;
        int r = 0;
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        int ans = INT_MAX;
        int s = 0;
        while(r < nums.size()){
            s += nums[r];
            while(s > target && l <= r){
                s -= nums[l];
                l++;
            }
            if(s == target){
                ans = min(ans, (int)nums.size() - (r - l + 1));
            }
            r++;
        }
        return ans > nums.size() ? -1 : ans;
    }
};