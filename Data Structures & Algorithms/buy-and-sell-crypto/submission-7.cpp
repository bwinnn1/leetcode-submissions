class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minBuy = prices[0];

        int maxP = 0;

        for (int i = 0; i < prices.size(); i++) {
            maxP = max(maxP, prices[i] - minBuy);

            // see if today's price is the cheapest so far 
            // if yes then i'd rather buy today instead of any day before
            // this is after compute the maximum profit for today
            minBuy = min(minBuy, prices[i]);
        }
        return maxP;
    }
};
