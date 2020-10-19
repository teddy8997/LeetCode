class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*
            將0 => -1這樣如果有一樣數量的1和0的話這個subarray的sum會是0
            使用一個map來記錄sum第一次出現的index
            如果這個sum出現在index i, j的話
            sum(i + 1, j) == 0
            ans = max(ans, j - i)
        */
        if(nums.empty()){
            return 0;
        }
        unordered_map<int, int> pos;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i]? 1 : -1; //0 => -1
            if(sum == 0){ //額外處理sum = 0 這個例子
                ans = i+1;
            }else if(pos.count(sum)){
                ans = max(ans, i - pos[sum]);
            }else{
                pos[sum] = i;
            }
        }
        return ans;
    }
};
//Time cpmplexity: O(n)
//Space complexity: O(n)