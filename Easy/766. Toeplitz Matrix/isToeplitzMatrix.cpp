/*
    只需要思考是不是每個元素都和左上或右下的元素比較是否相等即可
*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] != matrix[i - 1][j - 1]){
                    return false;
                }
            }
        }
        return true;
    }
};