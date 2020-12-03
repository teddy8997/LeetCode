/*
    暴力法:
    一個一個計算出每一列的總和然後將每一列的總和利用一個變數ans更新較大的值
    time complexity: O(m*n)
    space complexity: O(1)
*/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(int i = 0; i < accounts.size(); i++){
            int sum = 0;
            for(int j = 0; j < accounts[0].size(); j++){
                sum += accounts[i][j];                    
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};