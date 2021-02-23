/*
    二分法
    time complexity: O(logn)
    space complexity: O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while(l < r){
            int m = l + (r - l) / 2;
            int sum = numbers[l] + numbers[r];
            if(sum == target){
                return {l+1, r+1};
            }else if(sum < target){
                l++;
            }else if(sum > target){
                r--;
            }
        }
        return {-1,-1};
    }
};