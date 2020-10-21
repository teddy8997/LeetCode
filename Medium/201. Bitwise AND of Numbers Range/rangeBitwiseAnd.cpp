class Solution {
public:
    /*
        因為連續的數字她的bit都會從最低位元開始做0 1轉換
        例如:
        5 => 101
        6 => 110
        7 => 111
        可以觀察到連續的數字時,左邊會有一個共同的位元都是1 右邊則是沒有共同的位元
        所以我們只要比較頭尾的數字找出第一個不同的位元後後面都補0就是答案
        以上面的例子來看
        5 => 101
        7 => 111
        &)
        -------------
             100
    */
    int rangeBitwiseAnd(int m, int n) {
        bool isDifferent = false;
        int res = 0;
        for(int i = 30; i >= 0; i--){
            int dm = m & (1 << i);
            int dn = n & (1 << i);
            if(dm != dn){
                isDifferent = true;
            }
            if(isDifferent == false){
                res += dm;
            }
        }
        return res;
    }
};