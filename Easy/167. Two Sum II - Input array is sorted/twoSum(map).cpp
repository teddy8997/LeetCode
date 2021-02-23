/*
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < numbers.size(); i++){
            m[numbers[i]] = i;
        }
        for(int i = 0; i < numbers.size(); i++){
            if(m.count(target - numbers[i]) && i != m[target - numbers[i]]){
                return {i + 1, m[target - numbers[i]]+1};
            }
        }
        return {-1,-1};
    }
};