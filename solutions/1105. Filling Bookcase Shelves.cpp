class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            int j = i;
            int curr_width = 0;
            int curr_max = 0;
            while(j > 0 && curr_width <= shelf_width){
                curr_width += books[j-1][0];
                curr_max = max(curr_max, books[j-1][1]);
                if(curr_width <= shelf_width)
                    dp[i] = min(dp[i], dp[j-1]+curr_max);
                j--;
                
            }
            
        }
        return dp[n];
    }
};
