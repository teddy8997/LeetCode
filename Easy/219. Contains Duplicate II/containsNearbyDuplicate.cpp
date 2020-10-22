class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m; //利用map來記錄出現過的數以及他的index
        for(int i = 0; i < nums.size(); i++){
            //遍歷每個數 如果有出現在map中代表現在這個數是重複的 而且 如果現在這個數的index i 減去之前重複那個數index的絕對值小於k就是true
            if(m.count(nums[i]) && abs(i - m[nums[i]]) <= k){
                return true;
            }else{
                m[nums[i]] = i;
            }
        }
        return false;
    }
};