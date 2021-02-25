class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()) + 1;
        while(l < r){
            int m = l + (r - l) / 2;
            int cnt = 0;
            for(int p : piles){
                cnt += (p + m - 1) / m; //計算每一堆吃完要花多少時間
            }
            if(cnt > H){
                l = m + 1;
            }else{
                r = m;
            }
        }
        return r;
    }
};