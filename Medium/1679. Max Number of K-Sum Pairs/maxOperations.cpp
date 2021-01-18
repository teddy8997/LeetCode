/*
    排序後用兩個指標i,j分別指向最小的數及最大的數，若兩個數加起來和k相等答案就+1
    然後i++, j--
    如果兩數加起來小於k，則i++
    如果兩數加起來大於k，則j--
    time complexity: O(nlogn)
    space complexity: O(1)
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size()-1;
        int ans = 0;
        while(i < j){
            int n = nums[i] + nums[j];
            if(n == k){
                ans++;
                i++;
                j--;
            }else if(n < k){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};