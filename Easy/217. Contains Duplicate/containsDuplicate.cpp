class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	/*
    		Time complexity : O(nlogn)
    		Space complexity : O(1)
    	*/
    	//先由小到大排序
        sort(nums.begin(), nums.end()); //O(nlogn)
        //兩個兩個檢查是否重複
        for(int i = 1; i < nums.size(); i++){ //O(n)
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};