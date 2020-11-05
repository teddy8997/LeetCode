class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        /*
            利用C++內建的排序
            time complexity: O(n*log(n))
            space complexity: O(1)
        */
        /*
        sort(nums.begin(), nums.end());
        return nums;
        */
        
        /*
            brute force(TLE)
            time complexity: O(n^2)
            space complexity: O(1)
        */
        /*
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[j] < nums[i]){
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return nums;
        */
        /*
            quick sort
            Time complexity: O(nlogn) ~ O(n^2)
            Space complexity: O(logn) ~ O(n)

        */
        pivotQuicksort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    void pivotQuicksort(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int i = start;
        int j = end;
        int pivot = nums[i + (j - i) / 2];
        while(i <= j){
            while(i <= j && nums[i] < pivot){
                i++;
            }
            while(i <= j && nums[j] > pivot){
                j--;
            }
            if(i <= j){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;
                j--;
            }
        }
        pivotQuicksort(nums, i, end);
        pivotQuicksort(nums, start, j);
    }
    
};