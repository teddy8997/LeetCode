/*
	要求最大的個數就是看哪個區域是所有範圍都覆蓋到的，所以題目就是要我們找最小的那個矩形，也就是找到最小的長和寬即可，
	time complexity: O(n)
	space complexity: O(1)
*/

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int resultR = m;
        int resultC = n;
        for(vector<int> op : ops){
            resultR = min(resultR, op[0]);
            resultC = min(resultC, op[1]);
        }
        return resultR * resultC;
    }
};