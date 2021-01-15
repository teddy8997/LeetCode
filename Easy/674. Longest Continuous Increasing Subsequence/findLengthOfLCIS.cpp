/*
    一個一個遍歷數字，利用cur來記錄前一個數字，如果cur比當前的數字還小cnt++
    如果比較大則將計數器cnt = 1
    然後更新ans
    cur = 當前數字
    time complexity: O(n)
    space complexityL O(1)
*/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        int cur = INT_MAX;
        for(int n : nums){
            if(n > cur){
                cnt++;
            }else{
                cnt = 1;
            }
            ans = max(ans, cnt);
            cur = n;
        }
        return ans; 
    }
};