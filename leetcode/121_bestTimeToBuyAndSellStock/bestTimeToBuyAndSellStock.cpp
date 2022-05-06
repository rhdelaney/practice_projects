class Solution {
public:
    int maxProfit(vector<int>& prices) {
       /*int maxProfit = 0;
       for (int i = 0; i < prices.size();i++) {
           for (int j = i+1;j < prices.size();j++) {
               if (prices[j] - prices[i] > maxProfit) {
                   maxProfit = prices[j] - prices[i];
               }
           }
       }
        return maxProfit;
    */

        int profit = 0;
        int minvalue = INT_MAX;
        for (int i=0; i < prices.size();i++) {
          minvalue = min(minvalue,prices[i]);
          profit = max(profit, prices[i] - minvalue);
        }
        return profit;
    }
};
