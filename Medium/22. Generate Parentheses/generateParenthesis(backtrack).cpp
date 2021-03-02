/*
    題目是輸入一個整數 n 讓你計算 n 對括號能組成幾種合法的括號組合
    可以把問題改寫成
    現在有 2n 個位置，每個位置可以放 ( 或 ) ，組成的所有括號組合中有多少個是合法的?
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string track;
        backtrack(n, n, ans, track);
        return ans;
    }
private:
    void backtrack(int left, int right, vector<string> &ans, string &track){
        if(right < left){
            return;
        }
        if(left < 0 || right < 0){
            return;
        }
        if(left == 0 && right == 0){
            ans.push_back(track);
            return;
        }
        track.push_back('(');
        backtrack(left - 1, right, ans, track);
        track.pop_back();
        
        track.push_back(')');
        backtrack(left, right - 1, ans, track);
        track.pop_back();
    }
};