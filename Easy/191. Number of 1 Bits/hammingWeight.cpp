class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
            一個一個bit做比對 和1做&後如果為1代表那個bit是1所以計算次數就+1
            然後n往右位移一個bit繼續做判斷 直到n為0
            Time complexity: O(1)
            Space complexity: O(1)
        */
        int count = 0;
        while(n){
            int m = n & 1;
            if(m == 1){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};