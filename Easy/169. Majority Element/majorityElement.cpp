/*
    利用map紀錄每個數字出現的次數，再去看裡面哪個超過n / 2次
    
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n % 2 == 0? n / 2 : n / 2 + 1;
        unordered_map<int, int> m;
        for(int num : nums){
            m[num]++;
        }
        for(auto a : m){
            if(a.second >= threshold){
                return a.first;
            }
        }
        return -1;
    }
};