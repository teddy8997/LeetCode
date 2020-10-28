class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 1){
            return 0;
        }
        vector<int> min_prices(n);
        vector<int> max_profit(n);
        min_prices[0] = prices[0];
        max_profit[0] = 0;
        for(int i = 1; i < n; i++){
            //找出第i天前價錢最低的值
            min_prices[i] = min(min_prices[i-1], prices[i]);
            //一個一個去算不賣的時候 和 賣的時候哪個利潤比較大
            max_profit[i] = max(max_profit[i-1], prices[i] - min_prices[i-1]);
        }
        return max_profit[n-1];
    }
};