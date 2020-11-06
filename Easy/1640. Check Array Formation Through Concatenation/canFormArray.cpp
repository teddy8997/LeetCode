class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        /*
            因為題目說piece中的每個數列裡面的數字不能改順序
            所以我們只需要利用MAP來儲存pieces中每個index中數列裡第一個出現的數字及
            最後利用查表加到ans中
            最後檢查ans 和最初的arr內容有沒有相同
            Time complexity: O(n)
            Space complexity: O(n)
        */
        unordered_map <int, int> m;
        for(int i = 0; i < pieces.size(); i++){
            m[pieces[i][0]] = i;
        }
        vector<int> ans;
        for(int n : arr){
            if(!m.count(n)){
                continue;
            }
            ans.insert(ans.end(), pieces[m[n]].begin(), pieces[m[n]].end());
        }
        return ans == arr;
    }
};