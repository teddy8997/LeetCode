/*
    先將AB的兩兩之和求出然後在MAP中建立兩兩之和及出現次數的MAP，
    那麼只要在遍歷CD中任意兩數的和在看看MAP中存不存在這兩數之和的相反數就可以了
    time complexity: O(n^2)
    space complexity: O(n) 
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                m[A[i] + B[j]]++;
            }
        }
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                int target = -1 * (C[i] + D[j]);
                ans += m[target];
            }
        }
        return ans;
    }
};