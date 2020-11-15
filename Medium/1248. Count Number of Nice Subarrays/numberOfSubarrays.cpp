/*
    利用兩個指針start以及end，當end遍歷到奇數的時候k--
    當k = 0時代表sliding window裡面包含奇數個數已經為k個了
    此時移動start，如果當前star的數字是奇數的話則k++
    time complexity: O(n)
    space complexity: O(1)
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int ans = 0;
        int count = 0;
        while(end < nums.size()){
            if(nums[end] % 2 == 1){
                k--;
                count = 0;
            }
            while(k == 0){
                if(nums[start] % 2 == 1){
                   k++; 
                }
                start++;
                count++;
            }
            ans += count;
            end++;
        }
        return ans;
    }
};