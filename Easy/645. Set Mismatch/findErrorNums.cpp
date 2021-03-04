/*
    利用map紀錄每個元素的出現次數，如果次數為2就代表是重複的數字
    接下來從1遍歷到n 如果不在map中代表是不見的數字
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map <int, int> s;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            s[nums[i]]++;
            if(s[nums[i]] == 2){
                ans.push_back(nums[i]);
            }
        }
        for(int i = 1; i <= nums.size(); i++){
            if(!s.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};