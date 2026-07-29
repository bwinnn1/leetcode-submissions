class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        minbuy = prices[0]

        for sell in prices:
            maxP = max(maxP, sell-minbuy)
            minbuy = min(minbuy, sell)
    
        return maxP