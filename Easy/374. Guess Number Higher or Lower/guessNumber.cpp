/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        /*方法一 暴力法會TLE
        for(int i = 1; i <= n; i++){
            if(guess(i) == 0){
                return i;
            }
        }
        return n;
        */
        //方法二 二分法
        //利用2分法來降低時間複雜度
        int left = 0;
        int right = n;
        while(left <= right){
            int mid = left + (right - left) / 2;
            //若猜的數字小於對方要的，左邊邊界變mid+1
            if(guess(mid) == 1){
                left = mid+1;
            }else if(guess(mid) == -1){//若猜的數字大於對方要的，右邊邊界變mid
                right = mid;
            }else if(guess(mid) == 0){
                return mid;
            }
        }
        return -1;
    }
};