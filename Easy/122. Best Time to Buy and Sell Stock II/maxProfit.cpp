class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        //利用Greedy法來求解，使用一個變數profit來記錄最大利潤，只要不要是賠錢賣出的話就賣，並將賣出後獲得利潤加回profit中
        for(int i = 1; i < prices.size(); i++){
            profit += max(0, prices[i] - prices[i-1]); 
        }
        return profit;
    }
};