/*
    brute force
    核心想法:
    index i中可以接的水量為
    min(max(height[0...i]), max(height[i.....n-1])) - height[i]

*/
class Solution {
    public int trap(int[] height) {
        //BF
        int n = height.length;
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            int l_max = 0;
            int r_max = 0;
            for(int j = i; j < n; j++){
                r_max = Math.max(r_max, height[j]);
            }
            for(int j = i; j >= 0; j--){
                l_max = Math.max(l_max, height[j]);
            }
            ans += Math.min(l_max, r_max) - height[i];
        }
        return ans;
    }
}