/*
    time complexity: O(n)
    space complexity: O(n+m)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> tmp(n1 + n2);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                tmp[k] = nums1[i];
                i++;
            }else{
                tmp[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < n1){
            tmp[k] = nums1[i];
            i++;
            k++;
        }
        while(j < n2){
            tmp[k] = nums2[j];
            j++;
            k++;
        }
        if((n1 + n2) % 2 == 1){
            return tmp[(n1 + n2) / 2];
        }
        return ((double)tmp[(n1 + n2) / 2] + (double)tmp[(n1 + n2) / 2 - 1]) / 2; 
    }
};