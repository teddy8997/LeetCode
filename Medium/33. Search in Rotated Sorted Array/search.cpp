class Solution {
public:
    int search(vector<int>& nums, int target) {
        //這題經過觀察我們可以發現一定是左半邊或右半邊的值會是已經排序好的
        //所以我們二分法只要多判斷target到底在左半還是右半
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            //右半已經排序好的情況
            if(nums[mid] < nums[right]){
                //當要找的目標值介於右半邊的值之間
                if(target > nums[mid] && target <= nums[right]){
                    left = mid+1;
                }else{//當要找的目標值介於左半邊的值之間
                    right = mid-1;
                }
            }else{//左半已經排序好的情況
                //當要找的目標值介於左半邊的值之間
                if(target >= nums[left] && target < nums[mid]){
                    right = mid-1;
                }else{//當要找的目標值介於右半邊的值之間
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};