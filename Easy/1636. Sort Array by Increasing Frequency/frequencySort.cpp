class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        /*
            先用MAP紀錄每一個數字出現的次數
            再去查這個表格來排序
            Time complexity: O(n*log(n))
            Space complexity: O(n)
        */
        unordered_map<int, int> fq;
        for(int n : nums){
            fq[n]++;
        }
        sort(nums.begin(), nums.end(), [&](int A, int B){
            if(fq[A] == fq[B]){
                return A > B;
            }
            return fq[A] < fq[B];
        });
        return nums;
    }
};