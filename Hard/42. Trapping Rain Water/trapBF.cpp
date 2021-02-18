/*
    參考: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-42-trapping-rain-water/
    time complexity: O(n^2)
    space complexity: O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        auto sit = height.begin();
        auto eit = height.end();
        for(int i = 0 ; i < n; i++){
            int l = *max_element(sit, sit + i + 1);
            int r = *max_element(sit + i, eit);
            ans += min(l, r) - height[i];
        }
        return ans;
    }
};