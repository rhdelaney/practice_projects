class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxP += max(prices[i] - prices[i-1],0);
        }
        return maxP;
    }
};
