/*
	題目規定不能使用+-所以我們只能使用位元運算
	而做加法時每一位相加會有進位或沒進位，那麼我們將這兩部分拆開
	例如:759 + 674
	不考慮進位: 	323
	只考慮進位: 1110
	相加就是答案
	那不考慮進位的加 0 + 0 = 0, 0 + 1 = 1, 1 + 0 = 1, 1 + 1 = 0,這個就相當於是XOR
	考慮進位的加則是 0 + 0 = 0, 0 + 1 = 0, 1 + 0 = 0, 1 + 1 = 1,這個就相當於是&
	所以我們就可以解這題了
	最後相加時使用recursion終止條件為進位為0
*/

class Solution {
public:
    int getSum(int a, int b) {
        if(b == 0){
            return a;
        }
        int sum = a ^ b;
        int carry = (a & b & 0x7fffffff) << 1; //要和0x7fffffff做&是因為LEETCODE的編譯器不允許最高位非0的負數向左移所以我們將最高位強制清為0
        return getSum(sum, carry);
    }
};