class Solution {
public:
    int bitwiseComplement(int N) {
    	//利用1向左位移並和1做OR來做mask 直到mask大於你要處理的數字N
    	//若N = 5 => 101
    	//c = 111
        int c = 1;
        while(c < N){
            c = (c << 1) | 1;
        }
        //將mask和原數做XOR就能得到答案
        // 101 XOR 111 => 010 => 2
        return c ^ N;
    }
};