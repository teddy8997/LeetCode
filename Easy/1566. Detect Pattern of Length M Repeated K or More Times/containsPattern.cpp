/*
    由於數據規模不超過100所以我們可以使用暴力法
    由於pattern長度為m而且需要重複k次，所以pattern起始位置應該在[0, n - m * k]
    假設pattern起點為i,判斷後續[i+m, i + m * k)是否滿足條件，那其實我們只需判斷arr[j]是否與arr[j-m]相同
    time complexity: O(n^2)
    space complexity: O(1)
*/
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if(n < m * k){
            return false;
        }
        int i;
        int j;
        for(i = 0; i <= arr.size() - m * k; i++){
            for(j = i + m; j < i + m * k; j++){
               if(arr[j] != arr[j-m]){
                   break;
               }
            }
            if(j == i + m * k){
                return true;
            }
        }
        return false;
    }