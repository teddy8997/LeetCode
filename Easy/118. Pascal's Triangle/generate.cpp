/*
    主要就是第i列會有i個數字
    然後每一列的第一個數字跟最後一個都是1，否則是上一列的j和j-1的和
    time complexity: O(n^2)


*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> tmp;
            for(int j = 0; j <= i; j++){
                if(j == i || j == 0){ 
                    tmp.push_back(1);
                }else{
                    tmp.push_back(ans.back()[j-1] + ans.back()[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};