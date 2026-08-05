class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Hey duck! Here's the problem: I want to buy low and sell high,
        // but I can only sell AFTER I buy (no time travel allowed).
        // I need to find the best possible profit from one buy + one sell.

        // Start by assuming day 0 is my buy day. It might not be the best,
        // but I have to start somewhere, and I'll fix this guess as I go.
        int minBuy = prices[0];

        // If I never find a good trade, my profit is 0 (I just don't trade).
        // This also acts as a safety net: profit can never go negative,
        // because "doing nothing" is always an option.
        int maxProfit = 0;

        // Now I'm going to walk through the prices one day at a time, duck.
        for (int i = 0; i < prices.size(); i++) {

            // Question I ask myself every single day:
            // "If I had bought at the cheapest price I've seen SO FAR,
            // and sold today, how much would I make?"
            //
            // prices[i] - minBuy = profit if I sell today
            //
            // I compare that to the best profit I've found on any
            // earlier day, and keep whichever is bigger.
            maxProfit = max(maxProfit, prices[i] - minBuy);

            // Now, separately, I check: was today's price even LOWER
            // than the cheapest I've seen before? If so, today becomes
            // my new "best day to have bought."
            //
            // IMPORTANT, duck: I update minBuy AFTER computing profit above.
            // Why? Because I can't buy and sell on the exact same day.
            // If I updated minBuy first, I might accidentally compare
            // today's price to itself, which would always give 0
            // and could hide a real answer from an earlier day.
            minBuy = min(minBuy, prices[i]);
        }

        // After walking through every day, maxProfit holds the best
        // "sell today, given the cheapest earlier buy" answer I ever found.
        // That's the final answer, duck. Nothing left to check.
        return maxProfit;
    }
};