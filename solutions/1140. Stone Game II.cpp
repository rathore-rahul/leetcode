class Solution {
public:
    int dp[101][101];
    int stoneGameII(vector<int>& piles) {
        int total = 0;
        for(int x : piles)
            total += x;
        return solve(piles, 0, 1, total);
    }
    
    int solve(vector<int>& piles, int start, int M, int total){
        int n = piles.size();
        if(start >= n)
            return 0;
        if(dp[start][M])
            return dp[start][M];
        
        int opp = INT_MAX;
        int mine = 0;
        for(int x = 1; x <= 2*M; x++){
            int end = start + x -1;
            if(end >= n)
                break;
            mine += piles[start+x-1];
            opp = min(opp, solve(piles, end+1, max(M,x), total - mine));
        }
        
        dp[start][M] = total - opp;
        return total - opp;
    }
};
