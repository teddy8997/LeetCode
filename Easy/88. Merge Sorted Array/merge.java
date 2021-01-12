/*
    由於兩個數組都已經排序好了所以我們只要按順序比較大小。題目有說nums1有足夠大的空間所以我們不用重新resize，
    然後有給m及n所以我們可知道混和後的大小為m + n。我們使用三個遍量i, j, k分別來指向nums1的最末尾，nums2的最末尾,
    混和後的數組的最末尾。
    使用while循環比較，如果i>=0 && j >= 0就繼續迴圈，如果nums1[i] > nums2[j]就把nums1[i]加入到混和數組的末尾nums1[k]
    結束後i--, k--; 反之亦然
    最後有可能j還沒遍歷到0，所以要檢查繼續將nums2[j]的數給入混和數組中
    如果是i >= 0就不管，因為他的樹本身就在混和數組中

    time complexity: O(m + n)
    space complexity: O(1)

*/
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                k--;
                i--;
            }else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        
    }
}