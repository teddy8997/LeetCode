/*
    time complexity: O(n)
    space complexity: O(101)
*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> tmp(101, 0);
        for(int n : nums){
            tmp[n]++; 
        }
        int ans = 0;
        for(int n : nums){
            if(tmp[n] == 1){
                ans += n;
            }
        }
        return ans;
    }
};