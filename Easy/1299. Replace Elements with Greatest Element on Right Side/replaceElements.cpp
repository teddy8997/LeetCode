class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        /*
            從數組最尾端開始遍歷，然後紀錄最大值為多少
            time complexity: O(n)
            space complexity: O(1)
        */
        vector<int> ans(arr.size(), 0);
        int maxValue = arr[arr.size()-1];
        ans[arr.size()-1] = -1;
        for(int i = arr.size() - 2; i >= 0; i--){
            ans[i] = maxValue;
            if(maxValue < arr[i]){
                maxValue = arr[i];
            }
        }
        return ans;
    }
};