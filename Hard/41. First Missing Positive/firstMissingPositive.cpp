/*
    time complexity: O(n)
    time complexity: O(n)
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> appearNums;
        for (int n : nums) {
            appearNums.insert(n);
        }
        for (int i = 1; i <= INT_MAX; i++) {
            if (!appearNums.count(i)) {
                return i;
            }
        }
        return 0;
    }
};