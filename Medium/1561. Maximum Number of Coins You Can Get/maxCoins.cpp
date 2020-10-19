class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size() / 3;
        sort(piles.begin(), piles.end());
        int ans = 0;
        int count = 0;
        for(int i = piles.size() - 2; i >= 0; i -= 2){
            ans += piles[i];
            count++;
            if(count == n){
                break;
            }
        }
        return ans;
    }
};