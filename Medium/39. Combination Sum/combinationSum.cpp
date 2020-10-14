class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        //先將數組由小到大排列
        sort(candidates.begin(), candidates.end());
        //利用遞迴找出各種組合
        findSum(candidates, target, ans, 0, cur);
        return ans;
    }
private:
    void findSum(vector<int>& candidates, int target, vector<vector<int>> &ans, int d, vector<int> &cur){
        //若是目標值為0了就將目前的一種解存到最後要回傳的vector中 然後return
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        //嘗試各種組合
        for(int i = d; i < candidates.size(); i++){
            //如果數組中的值大於目標值就直接跳出迴圈
            if(candidates[i] > target){
                break;
            }
            //若小於目標值則將此值存入目前解的vector
            cur.push_back(candidates[i]);
            //繼續往下找，並將目標值減去剛剛加入的值
            findSum(candidates, target - candidates[i], ans, i, cur);
            //記得要移除最後加進來的值 讓之後的遞迴還能用此值
            cur.pop_back();
        }
        return;
    }
};