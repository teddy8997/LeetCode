class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        /*
            time complexity: O(N)
            space complexity: O(1)
        */
        int N = A.size();
        int i = 0;
        //往上走直到山頂
        while(i+1 < N && A[i] < A[i+1]){
            i++;
        }
        //山頂不能是第一個獲最後一個
        if(i == 0 || i == N-1){
            return false;
        }
        //從山頂往下走
        while(i+1 < N && A[i] > A[i+1]){
            i++;
        }
        //如果有順利走到最後一個 i == N-1
        return i == N-1;
    }
};