class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            法一sort
            Time complexity: O(nlogn)
            Space Complexity: O(1)
        */
        /*
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[n-1] != n){
            return n;
        }else if(nums[0] != 0){
            return 0;
        }
        for(int i = 1; i < n; i++){
            int expetedNum = nums[i - 1] + 1;
            if(nums[i] != expetedNum){
                return expetedNum;
            }
        }
        return -1;
        */
        /*
            法二 hashset
            先利用set把nums中的數保存進去，
            再從 0 ~ n一個一個找有沒有在set中，沒有的話就代表丟失了
            Time complexity: O(n)
            Space Complexity: O(1)
        */
        //unordered_set<int> s(nums.begin(), nums.end());
        unordered_set<int> s;
        for(int n : nums){
            s.insert(n);
        }
        for(int n = 0; n <= nums.size(); n++){
            if(!s.count(n)){
                return n;
            }
        }
        return -1; 
    }
};