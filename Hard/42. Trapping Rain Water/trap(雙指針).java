class Solution {
    public int trap(int[] height) {
        if(height.length == 0){
            return 0;
        }
        int n = height.length;
        int l = 0;
        int r = n - 1;
        int ans = 0;
        
        int l_max = height[0];
        int r_max = height[n - 1];
        while(l <= r){
            l_max = Math.max(l_max, height[l]);
            r_max = Math.max(r_max, height[r]);
            if(l_max < r_max){
                ans += l_max - height[l];
                l++;
            }else{
                ans += r_max - height[r];
                r--;
            }
        }
        return ans;
    }
}