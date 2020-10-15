class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        //這題題目要找出數組中只出現一次的數字
        //我們可以利用XOR的特性，所有數和0做XOR都會是自己，自己XOR自己為0
        //所以XOR到後面到最後一個數即可得知哪個數只出現一次
        /*
        a ^ a = 0
		a ^ 0 = a
		a ^ b ^ c = a ^ (b ^ c)

        */
        for(int n : nums){
            ans = ans ^ n;
        }
        return ans;
    }
};