class Solution {
public:
    bool judgeSquareSum(int c) {
        int n = sqrt(c);
        for(int i = n; i >= 0; i--){
            if(i * i == c){//如果平方後和原本C相等，代表是這種情況C=4, 2*2=4 再配個0變成0^2 +2^2 =4 
                return true;
            }
            //算出扣掉某個平方數後 剩下的值是不是也是某個數的平方數
            int d = c - i * i;
            int sd = sqrt(d);
            if(sd * sd == d){
                return true;
            }
        }
        return false;
    }
};