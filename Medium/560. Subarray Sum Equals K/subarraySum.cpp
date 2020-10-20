class Solution {
    public:
    int subarraySum(vector<int> nums, int k) {
        /*
        法一 暴力法 TLE
        找出每一種的subarray然後計算每一種subarray的和
        Time complexity : O(n^3) => 找每一種subarray 花了O(n^2) 算每一種array的和花了O(n)
        Space complexity : O(1)
        */
        /*
        int count = 0;
        int[] sum = new int[nums.length + 1];
        sum[0] = 0;
        for (int i = 1; i <= nums.length; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.length; start++) {
            for (int end = start + 1; end <= nums.length; end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
        */
        /*法二 累加 C++ 會TLE JAVA不會
        建立一個vector裡面存累加的值
        sum[i]表示累加到i-1的值
        所以我們要找subarray [i : j]的和的時候就利用sum[j+1] - sum[i]
        */
        int count = 0;
        vector<int> sum(nums.size()+1, 0);
        for(int i = 1; i <= nums.size(); i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for(int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
};