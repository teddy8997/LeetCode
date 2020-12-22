/*
	time complexity: O(n)
	space complexity: O(1)
*/
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxV = A[0];
        int minV = A[0];
        for(int num : A){
            maxV = max(maxV, num);
            minV = min(minV, num);
        }
        return max(0, maxV - minV - 2 *K);
    }
};