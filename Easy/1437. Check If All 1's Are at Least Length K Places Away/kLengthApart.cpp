/*
    計算兩個1之間有幾個0就好
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = k;
        for(int n : nums){
            if(n == 0){
                count++;
            }else{
                if(count < k){
                    return false;
                }
                count = 0;
            }
        }
        return true;
    }
};