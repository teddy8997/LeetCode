/*
    使用兩個DP數組f, g
    f[i] 代表從[0,i]範圍中包含nums[i]的最大乘積
    g[i] 代表從[0,i]範圍中包含nums[i]的最小乘積
    我們先初始化f[0], g[0]為nums[0]
    從數組中的第二個數開始遍歷那最大值和最小值只會在這三個數之間產生
    即f[i - 1] * nums[i], g[i - 1] * nums[i], nums[i]
    所以更新最大值即最小值就完成
    time complexity: O(n)
    space complexit: O(n)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> f(nums.size(), 0);
        vector<int> g(nums.size(), 0);
        int ans = nums[0];
        f[0] = nums[0];
        g[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            f[i] = max(max(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            g[i] = min(min(f[i - 1] * nums[i], g[i - 1] * nums[i]), nums[i]);
            ans = max(ans, f[i]);
        }
        return ans;
    }
};