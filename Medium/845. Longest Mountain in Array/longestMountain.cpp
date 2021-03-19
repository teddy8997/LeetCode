/*
    down =  [1,0,0,2,1,0,0]    
    up =    [0,0,1,2,0,0,1]
    找出i位置的左邊有多少個比arr[i]小的
    找出i位置的右邊有多少個比arr[i]小的
    
*/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> up(n);
        vector<int> down(n);
        for(int i = n - 2 ; i >= 0; i--){
            if(arr[i] > arr[i+1]){
                down[i] = down[i+1] + 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(i > 0 && arr[i] > arr[i - 1]){
                up[i] = up[i - 1] + 1;
            }
            if(up[i] > 0 && down[i] > 0){
                ans = max(ans, up[i] + down[i] + 1);
            }
        }
        return ans;
    }
};