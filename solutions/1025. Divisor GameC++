class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N+1,false);
        for(int i = 2; i <= N ;i++){
            for(int j = 1 ; j*j <= i ; j++ ){
                if(i%j == 0){
                    if(!dp[i-j]){
                        dp[i] = true;
                        break;
                    }
                    if(j != 1 && !dp[i-(i/j)]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[N];
    }
};
