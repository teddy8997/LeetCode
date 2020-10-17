class Solution {
public:
    bool isHappy(int n) {
        set <int> s;
        while(n != 1){
            int sum = 0;
            while(n){
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            n = sum;
            if(s.count(n)){
                return false;
            }
            s.insert(n);
        }
        return true;
    }
};
/*如果不是Happy Number會有以下規律
以11為例子
1^2 + 1^2 = 2
2^2 = 4
4^2 = 16
1^2 + 6^2 = 37
3^2 + 7^2 = 58
5^2 + 8^2 = 89
8^2 + 9^2 = 145
1^2 + 4^2 + 5^2 = 42
4^2 + 2^2 = 20
2^2 + 0^2 = 4
可以發現如果不是的話數字會重複，最後一行又出現4接下來順序又跟之前一樣
所以我們使用set來記錄有沒有出現過，如果出現過代表就不是Happ Number
*/