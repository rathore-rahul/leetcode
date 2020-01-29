class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int tsum  = 0;
        int n = stones.size();
        for(int x : stones)
            tsum += x;
        int sum = tsum/2;
        int max_ = 0;
        int dp[sum+1];
        for(int i = 0; i <= sum ;i++){
            dp[i] = 1e9;
        }
        dp[0] = -1;
        for(int i = 0; i < n ;i++){
            for(int j = 1; j <= sum ;j++){
                if(dp[j] < i)
                    continue;
                else if(j-stones[i] >= 0 && dp[j-stones[i]] < i ){
                    dp[j] = i;
                    max_ = max(max_,j);
                }
            }
        }
       return tsum-2*max_; 
    }
};
