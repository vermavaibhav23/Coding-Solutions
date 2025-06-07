//Best Time to Buy and Sell Stock
//Compiler - C++
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxprofit = 0;
        int i=1;
        while(i<prices.size()) {
            if(prices[i] < minprice) {
                minprice = prices[i];
            }
            else maxprofit = max(maxprofit, prices[i] - minprice);
            i++;
        }
        return maxprofit;
    }
};