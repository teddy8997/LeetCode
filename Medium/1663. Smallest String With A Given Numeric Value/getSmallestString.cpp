/*
    使用greedy, 從最後面向前填充字典序的最小值，我們先初始化回傳字串n個a來保證字串的長度，
    並將k的值先減去n, 接著用while來從後面用k和25比看哪個小，填入較小的，當k <= 0 則迴圈就會終止
    Time complexity: O(n)
    space complexity: O(1) 
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        k -= n;
        int i = n - 1;
        while(k > 0){
            int fill = min(k, 25);
            k -= fill;
            ans[i] += fill;
            i--;
        }
        return ans;
    }
};