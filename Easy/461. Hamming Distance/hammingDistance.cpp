class Solution {
public:
    int hammingDistance(int x, int y) {
        //題目求兩數的漢明距離，漢明距離就是兩數換成二進位後比較每個bit，不一樣的位置總數即是漢明距離
        //所以我們只要將兩數做XOR成 tmp，不同的bit就會是1
        //然後再做位元運算和1做&後看是不是1，是的話代表那個bit不同ans++
        //然後tmp向右位移1 bit
        int ans = 0;
        int tmp = x ^ y;
        while(tmp > 0){
            if(tmp & 1 == 1){
                ans++;
            }
            tmp >>= 1;
        }
        return ans;
    }
};