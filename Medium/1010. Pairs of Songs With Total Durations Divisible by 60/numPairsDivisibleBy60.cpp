/*
    利用tmp來記錄餘數為i的個數
    再去找能湊成60的餘數有沒有個數存在也就是(60 - t)
    ans += tmp[(60 - t) % 60]; =>若個數為0 加0不影響答案
    最後tmp[t]這個位置的餘數個數加一
    time complexity: O(n)
    space complexity: O(60)
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> tmp(60);
        int ans = 0;
        for(int t : time){
            t %= 60;
            ans += tmp[(60 - t) % 60];
            tmp[t]++;
        }
        return ans;
    }
};