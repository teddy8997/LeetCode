/*
    brute force(TLE)
    time complextiy: O(n^2)
    space com plexity: O(1)
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int maxWidth = 0;
        for(int i = 0; i < A.size()-1; i++){
            for(int j = i+1; j < A.size(); j++){
                if(A[i] <= A[j]){
                     maxWidth = max(maxWidth, j - i);
                }
            }
        }
        return maxWidth;
    }
};