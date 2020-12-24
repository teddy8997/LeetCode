/*
    這題題意是使用題目給定的n數字重新排列每一位找出第一個大於n的數
    這題是參考:https://www.cnblogs.com/grandyang/p/6716130.html
    例如n = 12443322
    我們可以重新排列第一個大於n的數是13222344
    我們可以從這兩個數字再觀察到，由左數來第2位由 2->3 然後後面的數字由降序變成升序排列
    現在有兩點要考慮
    1. 第二位2這個位是怎麼決定的?
    2. 3為什麼是跟3換?

    我們可以發現由右往左看時2是第一個小於右邊一位的位子，所以找出了轉折點。
    怎麼確定是跟3換呢? 我們也是由右往左看找到第一個大於2的數字就交換
    接下來只要把斷點之後的數字由小到大排列就是答案
    
    time complexity: O(nlog)
    space complexity: O(n)

*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();
        int i;
        for(i = len - 1; i > 0; i--){
            if(s[i] > s[i - 1]){
                break;
            }
        }
        if(i == 0){
            return -1;
        }
        for(int j = len - 1; j >= i; j--){
            if(s[j] > s[i - 1]){
                swap(s[j], s[i-1]);
                break;
            }
        }
        sort(s.begin() + i, s.end());
        long long ans = stoll(s);
        return ans > INT_MAX? -1 : ans;
    }
};