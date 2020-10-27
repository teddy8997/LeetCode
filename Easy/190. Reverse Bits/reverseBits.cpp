class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /*
            一個bit一個bit來處理，讓n和1做&後得到做右邊的bit然後再把這個bit位移到最左邊的bit位
            以此類推 最後就可以求出答案
            Time Complexity: O(1)
            Space Complexity: O(1)
        */
        uint32_t ans = 0;
        uint32_t power = 31;
        while(n != 0){
            ans += (n & 1) << power;
            n = n >> 1;
            power--;
        }
        return ans;
    }
};