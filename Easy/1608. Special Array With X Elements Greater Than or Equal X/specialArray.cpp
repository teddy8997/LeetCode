/*
    這題非常簡單依照題意即可寫出
    Time complexity: O(n)
    Space complexity: O(1)

*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int x = 0; x <= n; x++){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(count > x){
                    break;
                }
                if(nums[i] >= x){
                    count++;
                }
            }
            if(count == x){
                return x;
            }
        }
        return -1;
    }
};