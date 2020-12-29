/*
    將數列從小排到大，for從i = 0開始 搭配兩個指標s,t來選出三個數字
    s 選的是i的下一位
    t 則從最大的數開始遍歷
    一個一個算出和是否等於target，如果是的話就返回sum
    如果不是則計算出與target的差，並用一個ans及d來記錄最靠近target的值
    
    如果sum > target，t--
    sum < target, s++

    time complexity: O(n^2)
    space complexity: O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int d = INT_MAX;
        int ans = target;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            int s = i+1;
            int t = n-1;
            while(s < t){
                int sum = nums[i] + nums[s] + nums[t];
                if(sum == target){
                    return sum;
                }
                int diff = abs(sum - target);
                if(diff < d){
                    d = diff;
                    ans = sum;
                }
                if(sum > target){
                    t--;
                }else{
                    s++;
                }
            }
        }
        return ans;
    }
};