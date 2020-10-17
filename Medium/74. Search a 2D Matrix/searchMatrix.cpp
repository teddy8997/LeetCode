class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //如果是這種輸入直接回傳false
        //[] or [[]]
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int record = 0;
        //因為每個row中的元素都是排序好的而且每個row的最後一個數一定小於下一個row的第一個數字
        //所以我們一行一行判斷看看target是在哪一row的範圍，找到後記錄在哪一個row並跳出迴圈
        for(int i = 0; i < matrix.size(); i++){
            if(target <= matrix[i][matrix[i].size()-1] && target >= matrix[i][0]){
                record = i;
                break;
            }
        }
        //再去那一個row找有沒有target數字
        for(int i = 0; i < matrix[record].size(); i++){
            if(matrix[record][i] == target){
                return true;
            }
        }
        return false;
    }
};