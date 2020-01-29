class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        vector<int> sold(n,0);
        vector<int> un_sold(n,0);
        for(int i = 1; i < n; i++){
            un_sold[i] = sold[i] = sold[i-1];
            for(int j = 0; j < i; j++){
                int sell = prices[i] - prices[j];
                if(j == 0){
                    sold[i] = max(sold[i], sell);
                }
                else{
                    sold[i] = max(sold[i], sell + un_sold[j-1]);
                }
            }
        }
        return max(sold[n-1], un_sold[n-1]);
    }
};
