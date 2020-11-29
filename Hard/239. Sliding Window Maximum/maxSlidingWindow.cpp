/*
	法一: Brute Force
	Time complexity: O((n – k + 1) * k)
	Space complexity: O(1)
	
	TLE

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = k-1; i < nums.size(); i++){
            ans.push_back(*max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
        }
        return ans;
    }
};
