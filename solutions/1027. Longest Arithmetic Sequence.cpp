class Solution {
public:
    map<int,int> pos;
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<vector<int > >dp(n,vector<int>(n,2));
        pos[A[0]] = 0;
        int result = 2;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j < n; j++){
                int required = 2*A[i] - A[j];
                map<int,int>::iterator it = pos.find(required);
                if(it != pos.end()){
                    dp[i][j] = dp[it->second][i] + 1;
                    result = max(result, dp[i][j]);
                }
            }
            pos[A[i]] = i;
        }
        return result;
    }
};
