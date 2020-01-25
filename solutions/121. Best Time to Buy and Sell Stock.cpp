class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = INT_MAX;
        int curr_profit = 0;
        for(int i =0; i < prices.size(); i++){
            if(prices[i] - curr_min > curr_profit)
                curr_profit = prices[i] - curr_min;
            if(prices[i] < curr_min)
                curr_min = prices[i];
        }
        return curr_profit;
    }
};
