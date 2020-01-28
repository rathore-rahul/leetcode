class Solution {
public:
    vector<vector<pair<int,int> > > dp;
    pair<int,int> c = make_pair(0,0);
​
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n, vector<pair<int,int> > (n,c));
        helper(arr, 0, n-1);
        return dp[0][n-1].second;
    }
    
    void helper(vector<int>& arr, int start, int end){
        if(dp[start][end] != c) return;
        else if(start > end)
           return;
        else if(start == end){
            dp[start][start] = {arr[start], 0};
            return;
        }
        pair<int,int> max_ = {1e9,1e9};
        for(int i =start; i < end; i++){
            helper(arr, start,i);
            helper(arr,i+1,end);
            int sum = dp[start][i].second + dp[i+1][end].second + dp[start][i].first * dp[i+1][end].first;
            int max_mult = max(dp[start][i].first, dp[i+1][end].first);
            if(sum < max_.second || (sum == max_.second && max_mult < max_.first)){
                max_.second = min(max_.second,sum);
                max_.first = min(max_.first, max_mult);
            }
        }
        dp[start][end] = max_;
    }
};
