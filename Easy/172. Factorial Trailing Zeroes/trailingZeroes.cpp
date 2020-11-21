/*
	這題是要求一個是階乘尾數是0的個數，也就是要找乘數中10的個數
	那10可以分為2和5
	2的各數又遠比5還多所以我們就找出5的個數就行，需要注意的是像25,125這樣不只一個5的各數也要考慮進去
	time complexity: O(log5(n))
	space complexity: O(log5(n))
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while(n){
            ans += n / 5;
            n = n / 5;
        }
        return ans;
    }
};