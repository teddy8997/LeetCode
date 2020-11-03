class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) { 
        /*
            主要想法是遇到1 count++, 遇到0就檢查目前的1連續出現次數有沒有比之前最多1出現次數多
            有的話就更新
            time complexity: O(n)
            space complexity: O(1)
        */
        int maxCount = 0;
        int count = 0;
        for(int n : nums){
            if(n == 1){
                count++;
            }else{
                maxCount = max(maxCount,count);
                count = 0;
            }
        }
        maxCount = max(maxCount,count); //處理input = [1]情況
        return maxCount;
    }
};