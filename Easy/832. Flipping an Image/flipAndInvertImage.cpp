class Solution {
	/*
		Brute Force
		Time complexity: O(m*n)
		Space complexity: O(m*n)
	*/
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> ans = A;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[0].size(); j++){
                ans[i][j] = 1 - A[i][A.size() - 1 - j];
            }
        }
        return ans;
    }
};