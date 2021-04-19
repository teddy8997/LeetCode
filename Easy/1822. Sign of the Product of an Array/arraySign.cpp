/*
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countMinu = 0;
        for (auto n : nums) {
            if (n > 0) {
                continue;
            }else if (n < 0) {
                countMinu++;
            }else{
                return 0;
            }
        }
        return countMinu % 2 == 0? 1 : -1;
    }
};