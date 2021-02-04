/*
    題目給定偶數個數目的數組是否能兩兩配對時，每對和都是k的倍數，
    和是k的倍數我們可以寫成(a + b) % k == 0,
    取餘後和mod k為0 (a % k + b % k) % k == 0
    （即只要數 x mod k 和數 y mod k 的值相加等於 k ，就說明 x + y 能夠被 k 整除）
    統計a出現過的頻率檢查k - a的頻率是否相等
    餘數為0時則滿足頻率為偶數

*/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> fq(k);
        for(int x : arr){
            fq[(x % k + k) % k]++;
        }
        for(int i = 1; i < k; i++){
            if(fq[i] != fq[k - i]){
                return false;
            }
        }
        return fq[0] % 2 == 0;
    }
};