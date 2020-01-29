class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size()+1;
        int m = B.size()+1;
        int dp[n][m];
        int max_ = 0;
        memset(dp,0,sizeof(dp[0][0])*n*m);
        for(int i = 1; i < n ;i++){
            for(int j = 1; j < m; j++){
                if(A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = 0;
                max_ = max(max_, dp[i][j]);
            }
        }
     return max_;   
    }
};
