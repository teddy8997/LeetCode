class Solution {
public:
    int mySqrt(int x) {
        /*
            brute force
            time complexity: O(sqrt(n))
        */
        /*
        if(x <= 1){
            return x;
        }
        for(long long i = 1; i <= x; i++){
            if(i * i > x){
                return i - 1;
            }
        }
        return -1;
        */

        /*
            Binary search
            time complexity: O(logn)
            space complexity: O(1)
        */
        long l = 0;
        long r = static_cast<long>(x) + 1;
        while(l < r){
            long m = l + (r - l) / 2;
            if(m * m > x){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return l - 1;
    }
};