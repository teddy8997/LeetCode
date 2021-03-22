/*
    參考: https://zxi.mytechroad.com/blog/hashtable/leetcode-869-reordered-power-of-2/
    主要就是先建立N的MAP裡面存每一位數字的數量然後再一個一個去跟2的指數比較，如果MAP內容相同代表是true
    (因為題目有說N是1 <= N <= 10^9 且所以i有30位)
*/
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        auto m = countMap(N);
        for(int i = 0; i < 31; i++){
            if(m == countMap(1 << i)){
                return true;
            }
        }
        return false;
    }
private:
    map <int, int> countMap(int n){
        map<int, int> m;
        while(n){
            m[n % 10]++;
            n = n / 10;
        }
        return m;
    }
};