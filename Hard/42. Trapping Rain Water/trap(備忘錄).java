class Solution {
    public int trap(int[] height) {
        //BF + 備忘錄
        if(height.length == 0){
            return 0;
        }
        int n = height.length;
        int ans = 0;
        int [] l_max = new int [n];
        int [] r_max = new int [n];
        Arrays.fill(l_max, 0);
        Arrays.fill(r_max, 0);
        l_max[0] = height[0];
        r_max[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++){
            l_max[i] = Math.max(height[i], l_max[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--){
            r_max[i] = Math.max(height[i], r_max[i + 1]);
        }
        for(int i = 1; i < n - 1; i++){
            ans += Math.min(l_max[i], r_max[i]) - height[i];
        }
        return ans;
    }
}