class Solution {
public:
    bool isPowerOfThree(int n) {
        /*  法一 
        while(n && n % 3 == 0){
            n /= 3;
        }
        return n == 1;
        */
        /*
            法二:換底公式
            loga(b) = logc(b) / logc(a)
            如果n是3的倍數那麼log3(n)一定是整數
        */
        //所以我們只要檢查n是不是正數 並檢查log10(n) / log10(3)是否为整数
        return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};