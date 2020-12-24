/*
    直接暴力法解題
    j是nums1中的數字出現在nums2的位子
    k 是從j+1開始找到第一個大於nums2[j]的數
    
    time complexity: O(n^2)
    space complexity: O(n)
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            int j;
            int k = 0;
            for(j = 0; j < nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                   break; 
                }
            }
            for(k = j+1; k < nums2.size(); k++){
                if(nums2[k] > nums2[j]){
                    ans[i] = nums2[k];
                    break;
                }
            }
            if(k == nums2.size()){
                ans[i] = -1;
            }
        }
        return ans;
    }
};