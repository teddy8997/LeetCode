class Solution {
    public int maxProfit(int[] prices) {
        int curProfit = 0;
        int curMin = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < curMin) {
                curMin = prices[i];
            }
            int calProfit = prices[i] - curMin;
            if (curProfit < calProfit) {
                curProfit = calProfit;
            }
        }
        return curProfit;
    }
}