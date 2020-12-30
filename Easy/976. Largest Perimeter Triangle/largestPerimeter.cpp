/*
    題目要我們找出數組中能構成三角形的最大周長是多少
    能夠成一個三角形的條件是: 兩邊長的和大於第三個邊
    所以我們只需要將數組由小到大排序
    然後從最小的三個數開始檢測，檢測完後往右移下一個數再去檢測三個數
    如果符合構成三角形的定理就把他的sum記錄起來，若遇到比較長的就一直更新
    迴圈遍歷完後就是會是答案
    time complexity: O(nlogn)
    space complexity: O(1)

*/
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int sum = 0;
        for(int i = 0; i < A.size()-2; i++){
            if(A[i] + A[i+1] > A[i+2]){
                sum = max(sum, A[i] + A[i+1]+ A[i+2]);
            }
        }
        return sum;
    }
};