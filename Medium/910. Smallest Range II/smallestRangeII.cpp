/*
    這題求的條件為數組中的每個數都可以+K或是-K，然後求出最大最小值的差為最小
    一般我們直覺的想法是直接找數組的最大值-K，最小值+K
    可是這題不能這麼做
    以題目A = [1,3,6] K = 3 為例，把最大最小值分別+K-K後得到 [4,?,3] 因為每個數都可以+K或-K所以變3只能是0或6
    但這樣最大最小值就變了

    我們可以給原數組排序，在數組的i位置為界線，i之前都+K , i之後都-K
    前半段的最大值是A[i] + K , 最小值是A[0] + K
    後半段的最大值是A[n-1] - K, 最小值是A[i+1] - K
    所以整個數組最大值為 max(A[n-1] - K, A[i] + K)
    最小值為min(A[0] + K, A[i+1] - K)
    然後用ans一值更新這兩個差值的最小值就是答案

*/
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int n = A.size();
        int ans = A[n-1] - A[0];
        int left = A[0] + K;
        int right = A[n-1] - K;
        for(int i = 0; i < n-1; i++){
            int high = max(right, A[i] + K);
            int low = min(left, A[i+1] - K);
            ans = min(ans, high - low);
        }
        return ans;
    }
};