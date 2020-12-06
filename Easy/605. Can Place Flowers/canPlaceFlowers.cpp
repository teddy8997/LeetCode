/*
    主要是用貪婪法
    一開始的想法就是去掃給定的數組，如果n = 0或是整個數組掃完就停止
    掃到某個index i = 0的時候且flowerbed[i - 1] = 0且flowerbed[i + 1] = 0 時當前的index i就可以種花
    這邊要注意左右邊界處理
    1.如果當前index i = 0時且flowerbed[i+1] = 0則i這個位置可以種花
    2.如果當前index i = flowerbed.size() -1 時，且flowerbed[i-1] = 0則i這個位置可以種花
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int size = flowerbed.size();
        while(n > 0 && i < size){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size-1 || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                n--;
            }
            i++;
        }
        return n == 0;
    }
};