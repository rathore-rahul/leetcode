class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[target+1][d+1];
        memset(dp, 0, sizeof(dp[0][0])*(target+1)*(d+1));
        dp[0][0] = 1;
        int mod = 1e9+7;
        for(int i = 1; i <= d; i++){
            for(int j = 1; j <= target; j++){
                for(int k = 1; k <= f; k++){
                    if(j-k >=0 && dp[j-k][i-1] > 0){
                        dp[j][i]  = (dp[j][i] + dp[j-k][i-1])%mod;
                    }
                }
            }
        }
        return dp[target][d];
    }
};
