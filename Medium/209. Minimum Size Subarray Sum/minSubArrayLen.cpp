/*
    使用sliding window解
    先把end一直擴張直到比s大後開始縮減window，把start向右移，直到走到數列的尾巴
    time complexity: O(n)
    space complexity: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //sliding window
        int start = 0;
        int ans = INT_MAX;
        int sum = 0;
        for(int end = 0; end < nums.size(); end++){
            sum += nums[end];
            while(sum >= s){
                ans = min(ans, end - start + 1);
                sum = sum - nums[start];
                start++;
            }
        }
        return ans == INT_MAX? 0 : ans;
    }
};