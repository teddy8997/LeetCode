/*
    參考: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-42-trapping-rain-water/
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0){
            return 0;
        }
        int l = 0;
        int r = n - 1;
        int maxL = height[l];
        int maxR = height[r];
        int ans = 0;
        while(l < r){
            if(maxL < maxR){
                ans += maxL - height[l];
                maxL = max(maxL, height[++l]);
            }else{
                ans += maxR - height[r];
                maxR = max(maxR, height[--r]);
            }
        }
        return ans;
    }
};